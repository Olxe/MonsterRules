#pragma once

#include <SFML/Graphics.hpp>
#include <functional>

#include "../Game/Window/AssetManager.hpp"
#include "../Tools/ToolsFunction.h"

namespace gui
{
	class Widget: public sf::Drawable, public sf::Transformable
	{
	public:
		Widget();
		virtual ~Widget();

		void setMouseButtonReleasedCallback(std::function<void()> callback) { MouseButtonReleasedCallback = callback; }
		void setSize(const sf::Vector2f& size) { m_size = size; }
		sf::Vector2f getSize() const { return m_size; }
		sf::FloatRect GlobalBounds() const { return sf::FloatRect(this->getPosition(), m_size); }
		
		virtual void onEvent(sf::Event& event) {}
		virtual void onMouseMoved(float x, float y) {}
		virtual void onMouseButtonPressed(float x, float y) {}
		virtual void onMouseButtonReleased(float x, float y) {}
		virtual void onMouseWheelMoved(int delta) {}
		virtual void onKeyPressed(const sf::Event::KeyEvent& key) {}
		virtual void onKeyReleased(const sf::Event::KeyEvent& key) {}
		virtual void onTextEntered(sf::Uint32 unicode) {}

	protected:
		std::function<void()> MouseButtonReleasedCallback;

	private:
		sf::Vector2f m_size;

	};
}