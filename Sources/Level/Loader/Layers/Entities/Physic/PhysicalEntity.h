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

		void onUpdate(const float& deltaTime) override;
		void onDraw(sf::RenderWindow& window) const override;
		
		const sf::Vector2f& getPosition() const { return m_physicalBody->getPosition(); }
		float getRotation() const { return m_physicalBody->getRotation(); }

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

	private:
		bool isDebug = true;

	};
}

