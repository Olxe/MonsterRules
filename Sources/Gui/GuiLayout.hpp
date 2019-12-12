#pragma once

#include "Button.hpp"
#include "Label.hpp"

namespace gui
{
	class GuiLayout: public Widget
	{
	public:
		GuiLayout(sf::RenderWindow& window);
		~GuiLayout();

		void AddWidget(std::unique_ptr<gui::Widget> widget);
		sf::FloatRect GlobalBounds() const override;

		void onEvent(sf::Event& event) override;
		void onMouseMoved(float x, float y) override;
		void onMouseButtonPressed(float x, float y) override {}
		void onMouseButtonReleased(float x, float y) override;
		void onMouseWheelMoved(int delta) override {}
		void onKeyPressed(const sf::Event::KeyEvent& key) override {}
		void onKeyReleased(const sf::Event::KeyEvent& key) override {}
		void onTextEntered(sf::Uint32 unicode) override {}

	private:
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
		Widget* focus(const sf::Vector2f& mousePosition);

	private:
		std::vector<std::unique_ptr<gui::Widget>> m_widgets;
		sf::RenderWindow& m_window;

	};
}