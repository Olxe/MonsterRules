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
		ATTACK,
		INTERACT
	};

	class InputManager
	{
		struct sKey
		{
			bool isPressed;
			sf::Keyboard::Key key;
		};

		struct sButton
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
		bool bindButton(InputAction action, sf::Mouse::Button button);

	private:
		std::map<InputAction, sKey> m_keyboardBinds;
		std::map<InputAction, sButton> m_mouseBinds;

	};
}

#endif