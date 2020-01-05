#pragma once

#include "../Entity.hpp"
#include "PhysicalBody.h"

namespace entities
{
	class PhysicalEntity: public Entity
	{
	public:
		PhysicalEntity(Builder::SceneObject* obj);
		PhysicalEntity(Builder::ObjectTemplate* obj);
		virtual ~PhysicalEntity();

		virtual void onUpdate(const float& deltaTime);
		virtual void onDebugDraw(sf::RenderWindow& window);
		
		sf::Vector2f getPosition() const;
		float getRotation() const;

		virtual void CheckCollision(PhysicalEntity* pOther) {}
		virtual void CheckSensorCollision(PhysicalEntity* pOther) {}
		virtual void CheckEndContact(PhysicalEntity* pOther) {}
		virtual void CheckEndSensorContact(PhysicalEntity* pOther) {}

	protected:
		void addShapes(Builder::ObjectTemplate* obj, sf::Vector2f offset);
		void addPolygone(Builder::Polygone* polygone, sf::Vector2f offset, float density, bool isSensor);
		void addPolyline(Builder::Polygone* polyline, sf::Vector2f offset, float density, bool isSensor);
		void addCircle(Builder::Ellipse* ellipse, sf::Vector2f offset, float density, bool isSensor);
		void addRectangle(Builder::ObjectTemplate* rect, sf::Vector2f offset, float density, bool isSensor);
			
	protected:
		std::unique_ptr<PhysicalBody> m_physicalBody;

	};
}

