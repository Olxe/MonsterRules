#pragma once

#include "Widget.hpp"
#include "Label.hpp"

namespace gui
{
	class Button: public Widget
	{
	public:
		Button(const sf::Texture* texture, const sf::Vector2f& position, const std::string& label);
		~Button();

		void setPosition(const sf::Vector2f& position) override;
		void onMouseMoved(float x, float y) override;
		void onMouseButtonPressed(float x, float y) override;
		void onMouseButtonReleased(float x, float y) override;

	private:
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
		void press();
		void release();

	private:
		Label m_label;
		bool m_pressed;
	};
}