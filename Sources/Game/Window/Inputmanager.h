#ifndef __INPUTMANAGER__
#define __INPUTMANAGER__

#include <SFML/Window.hpp>
#include <map>

#include "Settings.h"

namespace Window
{
	enum class InputAction {
		MOVE_UP,
		MOVE_DOWN,
		MOVE_LEFT,
		MOVE_RIGHT,
		ATTACK_LEFT,
		ATTACK_MIDDLE,
		ATTACK_RIGHT,
		INTERACT
	};

	class InputManager
	{
		struct Key
		{
			bool isPressed;
			sf::Keyboard::Key key;
		};

		struct Button
		{
			bool isPressed;
			sf::Mouse::Button button;
		};

	public:
		InputManager();
		~InputManager();

		void SetBinds(Settings& settings);
		void Update();
		bool Action(InputAction idAction);

	private:
		bool bindKey(InputAction action, sf::Keyboard::Key key);
		bool bindButton(InputAction action, const sf::Mouse::Button& button);

	private:
		std::map<InputAction, Key> m_keyboardBinds;
		std::map<InputAction, Button> m_mouseBinds;

	};
}

#endif