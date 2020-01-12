#include "PhysicalEntity.h"

namespace entities
{
	PhysicalEntity::PhysicalEntity(Builder::SceneObject* obj)
		: CEntity(obj)
		, m_physicalBody(nullptr)
	{
		/////BODY CREATION/////
		b2BodyType type = (b2BodyType)obj->GetTile()->getProperty("physic").ToInt(0);
		bool isRotationFixed = obj->GetTile()->getProperty("fixedRotation").ToBool(true);
		m_physicalBody = std::unique_ptr<PhysicalBody>(new PhysicalBody(CEntity::getPosition(), CEntity::getRotation(), type, isRotationFixed, this));
		/////BODY CREATION/////

		/////FIXTURES CREATION/////
		for (auto& tile_obj : obj->GetTile()->getObjects()) {
			sf::Vector2f offset = tile_obj->getPosition() - this->getOrigin();
			this->addShapes(tile_obj.get(), offset);
		}
		/////FIXTURES CREATION/////
	}

	PhysicalEntity::PhysicalEntity(Builder::ObjectTemplate* obj)
		: CEntity(obj)
		, m_physicalBody(nullptr)
	{
		/////BODY CREATION/////
		b2BodyType type = (b2BodyType)obj->getProperty("physic").ToInt(0);
		bool isRotationFixed = obj->getProperty("fixedRotation").ToBool(true);
		m_physicalBody = std::unique_ptr<PhysicalBody>(new PhysicalBody(obj->getPosition(), obj->getRotation(), type, isRotationFixed, this));
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

		m_physicalBody->onUpdate();
	}

	void PhysicalEntity::onDebugDraw(sf::RenderWindow& window)
	{
		if (m_physicalBody.get()) {
			m_physicalBody->onDebugDraw(window);
		}
	}

	sf::Vector2f PhysicalEntity::getPosition() const
	{
		if (m_physicalBody.get()) {
			return m_physicalBody->getPosition();
		}
		return sf::Vector2f();
	}

	float PhysicalEntity::getRotation() const
	{
		if (m_physicalBody.get()) {
			return m_physicalBody->getRotation();
		}
		return 0.f;
	}

	void PhysicalEntity::addShapes(Builder::ObjectTemplate* obj, sf::Vector2f offset)
	{
		float density = obj->getProperty("density").ToFloat(1.f);
		bool isSensor = obj->getProperty("isSensor").ToBool(false);
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
			points.push_back(point.getPosition());
		}

		m_physicalBody->AddFixturePolygon(offset, points, density, isSensor);
	}

	void PhysicalEntity::addPolyline(Builder::Polygone* polyline, sf::Vector2f offset, float density, bool isSensor)
	{
		for (unsigned int i = 1; i < polyline->getPoints().size(); ++i) {
			sf::Vector2f p1 = polyline->getPoints()[i - 1].getPosition();
			sf::Vector2f p2 = polyline->getPoints()[i].getPosition();

			m_physicalBody->AddFixtureEdge(offset, p1, p2, density, isSensor);
		}
	}

	void PhysicalEntity::addCircle(Builder::Ellipse* ellipse, sf::Vector2f offset, float density, bool isSensor)
	{
		m_physicalBody->AddFixtureCircle(offset, ellipse->getSize().x / 2.f, density, isSensor);
	}

	void PhysicalEntity::addRectangle(Builder::ObjectTemplate* rect, sf::Vector2f offset, float density, bool isSensor)
	{
		m_physicalBody->AddFixtureRectangle(offset, rect->getSize(), rect->getRotation(), density, isSensor);
	}
}