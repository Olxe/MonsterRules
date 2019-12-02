#pragma once

#include "Widget.hpp"

namespace gui
{
	class Button: public Widget
	{
	public:
		Button(const sf::Texture* texture, const sf::Vector2f& position, const std::string& label, std::function<void(void)> callback = nullptr);
		~Button();

		void onStateChanged(State state) override;
		void onMouseMoved(float x, float y) override;
		void onMouseButtonPressed(int x, int y) override;
		void onMouseButtonReleased(int x, int y) override;
		void onKeyPressed(const sf::Event::KeyEvent& key) override;
		void onKeyReleased(const sf::Event::KeyEvent& key) override;

	private:
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
		void press();
		void release();

	private:
		sf::RectangleShape m_body;
		sf::Text m_label;
		bool m_pressed;
	};
}