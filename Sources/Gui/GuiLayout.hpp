#pragma once

#include "Button.hpp"
#include "Label.hpp"

namespace gui
{
	class GuiLayout: public Widget
	{
	public:
		GuiLayout(sf::RenderWindow& window, const sf::Vector2f& position);
		~GuiLayout();

		void AddWidget(std::unique_ptr<gui::Widget> widget);

		virtual void onEvent(sf::Event& event);
		virtual void onMouseMoved(float x, float y) {}
		virtual void onMouseButtonPressed(float x, float y) {}
		virtual void onMouseButtonReleased(float x, float y);
		virtual void onMouseWheelMoved(int delta) {}
		virtual void onKeyPressed(const sf::Event::KeyEvent& key) {}
		virtual void onKeyReleased(const sf::Event::KeyEvent& key) {}
		virtual void onTextEntered(sf::Uint32 unicode) {}

	private:
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
		gui::Widget* focus(const sf::Vector2f& mousePosition);

	private:
		std::vector<std::unique_ptr<gui::Widget>> m_widgets;
		sf::RenderWindow& m_window;

	};
}