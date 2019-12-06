#include "InputManager.h"

namespace Window
{
	InputManager::InputManager()
	{
	}

	InputManager::~InputManager()
	{
	}

	void InputManager::SetBinds(Settings& settings)
	{
		InputManager::bindKey(InputAction::MOVE_UP, sf::Keyboard::Z);
		InputManager::bindKey(InputAction::MOVE_DOWN, sf::Keyboard::S);
		InputManager::bindKey(InputAction::MOVE_LEFT, sf::Keyboard::Q);
		InputManager::bindKey(InputAction::MOVE_RIGHT, sf::Keyboard::D);
		InputManager::bindKey(InputAction::INTERACT, sf::Keyboard::E);

		InputManager::bindButton(InputAction::ATTACK_LEFT, sf::Mouse::Left);
		InputManager::bindButton(InputAction::ATTACK_MIDDLE, sf::Mouse::Middle);
		InputManager::bindButton(InputAction::ATTACK_RIGHT, sf::Mouse::Right);
	}

	bool InputManager::bindKey(InputAction action, sf::Keyboard::Key key)
	{
		sKey k = { false, key };
		m_keyboardBinds[action] = k;

		return true;
	}

	bool InputManager::bindButton(InputAction action, sf::Mouse::Button button)
	{
		sButton b = { false, button };
		m_mouseBinds[action] = b;
		return true;
	}

	void InputManager::Update()
	{
		for (auto& key : m_keyboardBinds) {
			key.second.isPressed = sf::Keyboard::isKeyPressed(key.second.key);
		}

		for (auto& button : m_mouseBinds) {
			button.second.isPressed = sf::Mouse::isButtonPressed(button.second.button);
		}
	}

	bool InputManager::Action(InputAction idAction)
	{
		auto key = m_keyboardBinds.find(idAction);
		if (key != m_keyboardBinds.end() && key->second.isPressed) {
			return true;
		}

		auto button = m_mouseBinds.find(idAction);
		if (button != m_mouseBinds.end() && button->second.isPressed) {
			return true;
		}

		return false;
	}
}