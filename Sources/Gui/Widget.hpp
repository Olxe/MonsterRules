#pragma once

#include <SFML/Graphics.hpp>
#include <functional>

#include "../Game/Window/AssetManager.hpp"
#include "../Tools/ToolsFunction.h"

namespace gui
{
	class Widget: public sf::Drawable
	{
	public:
		Widget();
		virtual ~Widget();

		void setMouseButtonReleasedCallback(std::function<void(void)> callback) { MouseButtonReleasedCallback = callback; }
		
		virtual void setPosition(const sf::Vector2f& position);
		sf::Vector2f getPosition() const { return m_position; }
		
		virtual void onEvent(sf::Event& event) {}
		virtual void onMouseMoved(float x, float y) {}
		virtual void onMouseButtonPressed(float x, float y) {}
		virtual void onMouseButtonReleased(float x, float y) {}
		virtual void onMouseWheelMoved(int delta) {}
		virtual void onKeyPressed(const sf::Event::KeyEvent& key) {}
		virtual void onKeyReleased(const sf::Event::KeyEvent& key) {}
		virtual void onTextEntered(sf::Uint32 unicode) {}

		sf::FloatRect GlobalBounds() const { return m_body.getGlobalBounds(); }

	protected:
		sf::RectangleShape m_body;
		std::function<void(void)> MouseButtonReleasedCallback;

	private:
		sf::Vector2f m_position;

	};
}