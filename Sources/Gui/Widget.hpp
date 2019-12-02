#pragma once

#include <SFML/Graphics.hpp>
#include <functional>

#include "../Game/Window/AssetManager.hpp"
#include "../Tools/ToolsFunction.h"

namespace gui
{
	enum class State
	{
		StateDefault,
		StateHovered,
		StatePressed,
		StateFocused
	};

	class Widget: public sf::Drawable, public sf::Transformable
	{
	public:
		Widget();
		virtual ~Widget();

		void TriggerCallback() const;
		void setCallback(std::function<void(void)> callback) { m_callback = callback; }
		void setPosition(const sf::Vector2f& position) { m_position = position; }

		sf::Vector2f getPosition() const { return m_position; }
		
		virtual void onStateChanged(State state) {}
		virtual void onMouseMoved(float x, float y) {}
		virtual void onMouseButtonPressed(int x, int y) {}
		virtual void onMouseButtonReleased(int x, int y) {}
		virtual void onMouseWheelMoved(int delta) {}
		virtual void onKeyPressed(const sf::Event::KeyEvent& key) {}
		virtual void onKeyReleased(const sf::Event::KeyEvent& key) {}
		virtual void onTextEntered(sf::Uint32 unicode) {}

	private:
		std::function<void(void)> m_callback;
		sf::Vector2f m_position;
	};
}