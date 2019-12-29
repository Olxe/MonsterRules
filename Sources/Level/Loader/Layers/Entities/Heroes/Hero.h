#pragma once

#include "../../../../../Game/Window/WindowManager.hpp"
#include "../Physic/PhysicalEntity.h"
#include "../AnimatedEntity.h"

namespace entities
{
	enum class Direction
	{
		UP,
		DOWN,
		LEFT,
		RIGHT
	};

	class Hero: public PhysicalEntity
	{
	public:
		Hero(Builder::SceneObject* obj);
		virtual ~Hero();

		void onUpdate(const float& deltaTime) override;
		virtual void onAnimationFinished(const std::string& name, const std::string& type);

		void CheckCollision(PhysicalEntity* pOther) override {}
		void CheckSensorCollision(PhysicalEntity* pOther) override {}
		void CheckEndContact(PhysicalEntity* pOther) override {}
		void CheckEndSensorContact(PhysicalEntity* pOther) override {}

	protected:
		virtual void onMove(const sf::Vector2i& velocity, const float& deltaTime);
		virtual void onAttack(const sf::Vector2f& mousePosition);

	private:
		void inputReading(const float& deltaTime);

	protected:
		AnimatedEntity m_animations;

	private:
		float m_speed = 500;
		Direction m_currentDirection;
		sf::Vector2i m_lastVelocity;

	};
}

