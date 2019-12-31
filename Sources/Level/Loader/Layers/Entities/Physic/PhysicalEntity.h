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

	private:
		void addPolygone(Builder::Polygone* polygone, float density, bool isSensor);
		void addPolyline(Builder::Polygone* polyline, float density, bool isSensor);
		void addCircle(Builder::Ellipse* ellipse, float density, bool isSensor);
		void addRectangle(Builder::ObjectTemplate* rect, float density, bool isSensor);
			
	protected:
		std::unique_ptr<PhysicalBody> m_physicalBody;

	private:
		bool isDebug = true;

	};
}

