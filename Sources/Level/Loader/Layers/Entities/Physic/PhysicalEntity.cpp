#include "PhysicalEntity.h"

namespace entities
{
	PhysicalEntity::PhysicalEntity(Builder::SceneObject* obj)
		: Entity(obj)
		, m_physicalBody(nullptr)
	{
		/////BODY CREATION/////
		b2BodyType type = b2BodyType::b2_staticBody;
		bool isRotationFixed = true;
		if (const Parser::PropertiesNode* tile_properties = dynamic_cast<const Parser::PropertiesNode*>(obj->GetTile()->getProperties())) {
			type = (b2BodyType)obj->GetTile()->getProperties()->GetProperty("physic").ToInt(0);
			isRotationFixed = obj->GetTile()->getProperties()->GetProperty("fixedRotation").ToBool(true);
		}
		m_physicalBody = std::unique_ptr<PhysicalBody>(new PhysicalBody(Entity::getPosition(), Entity::getRotation(), type, isRotationFixed, this));
		/////BODY CREATION/////

		/////FIXTURES CREATION/////
		for (auto tile_obj : obj->GetTile()->GetObjects()) {
			sf::Vector2f offset = sf::Vector2f(tile_obj->GetX(), tile_obj->GetY()) - this->getOrigin();
			this->addShapes(tile_obj, offset);
		}
		/////FIXTURES CREATION/////
	}

	PhysicalEntity::PhysicalEntity(Builder::ObjectTemplate* obj)
		: Entity(obj)
		, m_physicalBody(nullptr)
	{
		/////BODY CREATION/////
		b2BodyType type = b2BodyType::b2_staticBody;
		bool isRotationFixed = true;
		if (const Parser::PropertiesNode* tile_properties = dynamic_cast<const Parser::PropertiesNode*>(obj->getProperties())) {
			type = (b2BodyType)obj->getProperties()->GetProperty("physic").ToInt(0);
			isRotationFixed = obj->getProperties()->GetProperty("fixedRotation").ToBool(true);
		}
		m_physicalBody = std::unique_ptr<PhysicalBody>(new PhysicalBody(sf::Vector2f(obj->GetX(), obj->GetY()), obj->GetRotation(), type, isRotationFixed, this));
		/////BODY CREATION/////

		/////FIXTURES CREATION/////
		this->addShapes(obj, sf::Vector2f(0, 0));
		/////FIXTURES CREATION/////
	}

	PhysicalEntity::~PhysicalEntity()
	{
	}

	void PhysicalEntity::onUpdate(const float& deltaTime)
	{
		this->setPosition(this->getPosition());
		this->setRotation(this->getRotation());
		
		if (isDebug) m_physicalBody->onUpdate();
	}

	void PhysicalEntity::onDraw(sf::RenderWindow& window) const
	{
		Entity::onDraw(window);

		if (isDebug) m_physicalBody->onDraw(window);
	}

	void PhysicalEntity::addShapes(Builder::ObjectTemplate* obj, sf::Vector2f offset)
	{
		float density = 1.f;
		bool isSensor = false;
		if (const Parser::PropertiesNode* properties = dynamic_cast<const Parser::PropertiesNode*>(obj->getProperties())) {
			density = properties->GetProperty("density").ToFloat(1.f);
			isSensor = properties->GetProperty("isSensor").ToBool(false);
		}

		if (Builder::Polygone* polygone = dynamic_cast<Builder::Polygone*>(obj)) {
			if (polygone->getCategory() == Builder::PolygoneType::POLYGONE) {
				this->addPolygone(polygone, offset, density, isSensor);
			}
			else {
				this->addPolyline(polygone, offset, density, isSensor);
			}
		}
		else if (Builder::Ellipse* ellipse = dynamic_cast<Builder::Ellipse*>(obj)) {
			this->addCircle(ellipse, offset, density, isSensor);
		}
		else {
			this->addRectangle(obj, offset, density, isSensor);
		}
	}

	void PhysicalEntity::addPolygone(Builder::Polygone* polygone, sf::Vector2f offset, float density, bool isSensor)
	{
		std::vector<sf::Vector2f> points;
		for (auto& point : polygone->getPoints()) {
			points.push_back(sf::Vector2f(point.GetX(), point.GetY()));
		}

		m_physicalBody->AddFixturePolygon(offset, points, density, isSensor);
	}

	void PhysicalEntity::addPolyline(Builder::Polygone* polyline, sf::Vector2f offset, float density, bool isSensor)
	{
		for (unsigned int i = 1; i < polyline->getPoints().size(); ++i) {
			sf::Vector2f p1 = sf::Vector2f(polyline->getPoints()[i - 1].GetX(), polyline->getPoints()[i - 1].GetY());
			sf::Vector2f p2 = sf::Vector2f(polyline->getPoints()[i].GetX(), polyline->getPoints()[i].GetY());

			m_physicalBody->AddFixtureEdge(offset, p1, p2, density, isSensor);
		}
	}

	void PhysicalEntity::addCircle(Builder::Ellipse* ellipse, sf::Vector2f offset, float density, bool isSensor)
	{
		m_physicalBody->AddFixtureCircle(offset, ellipse->GetWidth() / 2.f, density, isSensor);
	}

	void PhysicalEntity::addRectangle(Builder::ObjectTemplate* rect, sf::Vector2f offset, float density, bool isSensor)
	{
		m_physicalBody->AddFixtureRectangle(offset, sf::Vector2f(rect->GetWidth(), rect->GetHeight()), rect->GetRotation(), density, isSensor);
	}
}