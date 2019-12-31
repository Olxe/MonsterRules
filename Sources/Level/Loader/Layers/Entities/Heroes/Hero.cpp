#include "Hero.h"

namespace entities
{
	Hero::Hero(Builder::SceneObject* obj)
		: PhysicalEntity(obj)
		, m_currentDirection(Direction::DOWN)
	{
		m_animations.setCallBack([&](const std::string& name, const std::string& type) { this->onAnimationFinished(name, type); });
	}

	Hero::~Hero()
	{
	}

	void Hero::onUpdate(const float& deltaTime)
	{
		PhysicalEntity::onUpdate(deltaTime);

		this->inputReading(deltaTime);

		m_animations.Update(deltaTime);
	}

	void Hero::onMove(const sf::Vector2i& velocity, const float& deltaTime)
	{
		if (velocity.x == 0 || velocity.y == 0) m_lastVelocity = sf::Vector2i(0, 0);

		if (m_lastVelocity.y > velocity.y) m_currentDirection = Direction::UP;
		if (m_lastVelocity.y < velocity.y) m_currentDirection = Direction::DOWN;
		if (m_lastVelocity.x > velocity.x) m_currentDirection = Direction::LEFT;
		if (m_lastVelocity.x < velocity.x) m_currentDirection = Direction::RIGHT;

		m_lastVelocity = velocity;

		if (!m_animations.Actived() || m_animations.getType() != "ATTACK")
		{
			if (abs(velocity.x) == 1 || abs(velocity.y) == 1)
			{
				if (m_currentDirection == Direction::UP) m_animations.Start("WALK_BACK");
				if (m_currentDirection == Direction::DOWN) m_animations.Start("WALK_FRONT");
				if (m_currentDirection == Direction::LEFT) m_animations.Start("WALK_LEFT");
				if (m_currentDirection == Direction::RIGHT) m_animations.Start("WALK_RIGHT");
			}
			else if (velocity == sf::Vector2i(0, 0))
			{
				if (m_currentDirection == Direction::UP) m_animations.Start("IDLE_BACK");
				if (m_currentDirection == Direction::DOWN) m_animations.Start("IDLE_FRONT");
				if (m_currentDirection == Direction::LEFT) m_animations.Start("IDLE_LEFT");
				if (m_currentDirection == Direction::RIGHT) m_animations.Start("IDLE_RIGHT");
			}
		}
		
		float speed = m_speed;
		if (abs(velocity.x) == 1 && abs(velocity.y) == 1) speed /= 1.33f;//pythagore speed
		m_physicalBody->getBody()->SetLinearVelocity(b2Vec2(velocity.x * speed * deltaTime, velocity.y * speed * deltaTime));
	}

	void Hero::onAttack(const sf::Vector2f& mousePosition)
	{
		sf::Vector2f vecDirection = mousePosition - this->getPosition();
		float angle = std::atan2f(vecDirection.y, vecDirection.x) * 180.f / 3.14f;

		if (angle < 0.0f) angle = 360.0f + angle;
		else if (angle > 360.0f) angle -= 360.0f;

		if (angle >= 225.f && angle <= 315.f) {
			m_currentDirection = Direction::UP;
			m_animations.Start("ATTACK_BACK", "ATTACK", true, false);
		}
		else if (angle >= 45.f && angle <= 135.f) {
			m_currentDirection = Direction::DOWN;
			m_animations.Start("ATTACK_FRONT", "ATTACK", true, false);
		}
		else if (angle > 135.f && angle < 225.f) {
			m_currentDirection = Direction::LEFT;
			m_animations.Start("ATTACK_LEFT", "ATTACK", true, false);
		}
		else if ((angle > 315.f && angle <= 360.f) || (angle >= 0.f && angle < 45.f)) {
			m_currentDirection = Direction::RIGHT;
			m_animations.Start("ATTACK_RIGHT", "ATTACK", true, false);
		}
	}

	void Hero::onAnimationFinished(const std::string& name, const std::string& type)
	{
		//Out(name, type);
	}

	void Hero::inputReading(const float& deltaTime)
	{
		Window::InputManager* input = Window::WindowManager::Instance()->GetInputs();
		sf::Vector2i velocity = sf::Vector2i(0, 0);

		if (input->Action(Window::InputAction::ATTACK)) {
			if (m_animations.getType() != "ATTACK")
			{
				m_animations.Stop();
			}

			sf::Vector2f mousePosition = Window::WindowManager::Instance()->GetWindow()->getMousePosition();
			this->onAttack(mousePosition);
		}
		else {
			if (m_animations.Actived() && m_animations.getType() == "ATTACK")
			{
				m_animations.Stop();
			}

			if (input->Action(Window::InputAction::MOVE_UP)) {
				velocity.y += -1;
			}
			if (input->Action(Window::InputAction::MOVE_DOWN)) {
				velocity.y += 1;
			}
			if (input->Action(Window::InputAction::MOVE_LEFT)) {
				velocity.x += -1;
			}
			if (input->Action(Window::InputAction::MOVE_RIGHT)) {
				velocity.x += 1;
			}
		}

		this->onMove(velocity, deltaTime);
	}
}