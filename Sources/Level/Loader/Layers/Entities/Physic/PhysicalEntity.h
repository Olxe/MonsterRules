#pragma once

#include "../Entity.hpp"
#include "PhysicalBody.h"

namespace entities
{
	class PhysicalEntity: public Entity
	{
	public:
		PhysicalEntity(Builder::SceneObject* obj);
		virtual ~PhysicalEntity();

		void onUpdate(const float& deltaTime) override;
		void onDraw(sf::RenderWindow& window) const override;

		virtual void CheckCollision(PhysicalEntity* pOther) {}
		virtual void CheckSensorCollision(PhysicalEntity* pOther) {}
		virtual void CheckEndContact(PhysicalEntity* pOther) {}
		virtual void CheckEndSensorContact(PhysicalEntity* pOther) {}

			
	protected:
		std::unique_ptr<PhysicalBody> m_physicalBody;
		bool isDebug = true;

	};
}

