#include "Archer.h"

namespace entities
{
	Archer::Archer(Builder::Object* obj, int id)
		: Entity(obj, id)
	{
	}

	Archer::~Archer()
	{
	}

	void Archer::onUpdate(const float& deltaTime)
	{
		input(deltaTime);
	}

	void Archer::onDraw(sf::RenderWindow& window)
	{
		Entity::onDraw(window);
	}

	void Archer::input(const float& deltaTime)
	{
		Window::InputManager* in = Window::WindowManager::Instance()->GetInputs();

		sf::Vector2f direction = sf::Vector2f(0, 0);
		float speed = 300;

		if (in->Action(Window::InputAction::MOVE_UP)) {
			direction.y = -1;
		}
		if (in->Action(Window::InputAction::MOVE_DOWN)) {
			direction.y = 1;
		}
		if (in->Action(Window::InputAction::MOVE_LEFT)) {
			direction.x = -1;
		}
		if (in->Action(Window::InputAction::MOVE_RIGHT)) {
			direction.x = 1;
		}

		this->move(direction * speed * deltaTime);
	}
}