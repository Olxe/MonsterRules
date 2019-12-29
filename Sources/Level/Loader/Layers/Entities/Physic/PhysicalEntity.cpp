#include "PhysicalEntity.h"

namespace entities
{
	PhysicalEntity::PhysicalEntity(Builder::SceneObject* obj)
		: Entity(obj)
		, m_physicalBody(nullptr)
	{
		b2BodyType type = b2BodyType::b2_staticBody;
		if (obj->GetTile()->getProperties()->GetProperty("physic").ToString() == "dynamic") type = b2BodyType::b2_dynamicBody;
		if (obj->GetTile()->getProperties()->GetProperty("physic").ToString() == "kinematic") type = b2BodyType::b2_kinematicBody;
		bool isRotationFixed = obj->GetTile()->getProperties()->GetProperty("fixedRotation").ToBool(true);

		m_physicalBody = std::unique_ptr<PhysicalBody>(new PhysicalBody(this->getPosition(), this->getRotation(), type, isRotationFixed, this));

		for (auto it : obj->GetTile()->GetObjects()) {
			if (Builder::Polygone* o = dynamic_cast<Builder::Polygone*>(it)) {

			}
			else if (Builder::Ellipse* e = dynamic_cast<Builder::Ellipse*>(it)) {
				sf::Vector2f offset = sf::Vector2f(e->GetX() + e->GetWidth() / 2.f - obj->GetTile()->GetWidth() / 2.f,
					e->GetY() + e->GetHeight() / 2.f - obj->GetTile()->GetHeight() / 2.f);

				float density = it->getProperties()->GetProperty("density").ToFloat(1.f);
				bool isSensor = it->getProperties()->GetProperty("isSensor").ToBool(false);

				m_physicalBody->AddFixtureCircle(offset, e->GetWidth() / 2.f , density, isSensor);
			}
			else{
				sf::Vector2f offset = sf::Vector2f(it->GetX() + it->GetWidth() / 2.f - obj->GetTile()->GetWidth() / 2.f,
					it->GetY() + it->GetHeight() / 2.f - obj->GetTile()->GetHeight() / 2.f);

				float density = it->getProperties()->GetProperty("density").ToFloat(1.f);
				bool isSensor = it->getProperties()->GetProperty("isSensor").ToBool(false);

				m_physicalBody->AddFixtureRectangle(offset,
					sf::Vector2f(it->GetWidth(), it->GetHeight()), it->GetRotation(), density, isSensor);
			}
		}
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
}