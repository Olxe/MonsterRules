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
		m_physicalBody = std::unique_ptr<PhysicalBody>(new PhysicalBody(this->getPosition(), this->getRotation(), type, isRotationFixed, this));
		/////BODY CREATION/////

		/////FIXTURES CREATION/////
		for (auto tile_obj : obj->GetTile()->GetObjects()) {
			this->addShapes(tile_obj);
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
		obj->SetPosition(0, 0);
		/////FIXTURES CREATION/////
		this->addShapes(obj);
		/////FIXTURES CREATION/////
	}

	PhysicalEntity::~PhysicalEntity()
	{
	}

	void PhysicalEntity::onUpdate(const float& deltaTime)
	{
		this->setPosition(m_physicalBody->getPosition());
		this->setRotation(m_physicalBody->getRotation());
		
		if (isDebug) m_physicalBody->onUpdate();
	}

	void PhysicalEntity::onDraw(sf::RenderWindow& window) const
	{
		Entity::onDraw(window);

		if (isDebug) m_physicalBody->onDraw(window);
	}

	void PhysicalEntity::addShapes(Builder::ObjectTemplate* obj)
	{
		float density = 1.f;
		bool isSensor = false;
		if (const Parser::PropertiesNode* properties = dynamic_cast<const Parser::PropertiesNode*>(obj->getProperties())) {
			density = properties->GetProperty("density").ToFloat(1.f);
			isSensor = properties->GetProperty("isSensor").ToBool(false);
		}

		if (Builder::Polygone* polygone = dynamic_cast<Builder::Polygone*>(obj)) {
			if (polygone->getCategory() == Builder::PolygoneType::POLYGONE) {
				this->addPolygone(polygone, density, isSensor);
			}
			else {
				this->addPolyline(polygone, density, isSensor);
			}
		}
		else if (Builder::Ellipse* ellipse = dynamic_cast<Builder::Ellipse*>(obj)) {
			this->addCircle(ellipse, density, isSensor);
		}
		else {
			this->addRectangle(obj, density, isSensor);
		}
	}

	void PhysicalEntity::addPolygone(Builder::Polygone* polygone, float density, bool isSensor)
	{
		sf::Vector2f offset = sf::Vector2f(polygone->GetX(), polygone->GetY()) - this->getOrigin();
		std::vector<sf::Vector2f> points;
		for (auto& point : polygone->getPoints()) {
			points.push_back(sf::Vector2f(point.GetX(), point.GetY()));
		}

		m_physicalBody->AddFixturePolygon(offset, points, density, isSensor);
	}

	void PhysicalEntity::addPolyline(Builder::Polygone* polyline, float density, bool isSensor)
	{
		sf::Vector2f offset = sf::Vector2f(polyline->GetX(), polyline->GetY()) - this->getOrigin();
		Out(offset.x, offset.y);
		for (unsigned int i = 1; i < polyline->getPoints().size(); ++i) {
			sf::Vector2f p1 = sf::Vector2f(polyline->getPoints()[i - 1].GetX(), polyline->getPoints()[i - 1].GetY());
			sf::Vector2f p2 = sf::Vector2f(polyline->getPoints()[i].GetX(), polyline->getPoints()[i].GetY());

			m_physicalBody->AddFixtureEdge(offset, p1, p2, density, isSensor);
		}
	}

	void PhysicalEntity::addCircle(Builder::Ellipse* ellipse, float density, bool isSensor)
	{
		sf::Vector2f offset = sf::Vector2f(ellipse->GetX() + ellipse->GetWidth() / 2.f, ellipse->GetY() + ellipse->GetHeight() / 2.f) - this->getOrigin();

		m_physicalBody->AddFixtureCircle(offset, ellipse->GetWidth() / 2.f, density, isSensor);
	}

	void PhysicalEntity::addRectangle(Builder::ObjectTemplate* rect, float density, bool isSensor)
	{
		sf::Vector2f offset = sf::Vector2f(rect->GetX() + rect->GetWidth() / 2.f, rect->GetY() + rect->GetHeight() / 2.f) - this->getOrigin();

		m_physicalBody->AddFixtureRectangle(offset, sf::Vector2f(rect->GetWidth(), rect->GetHeight()), rect->GetRotation(), density, isSensor);
	}
}