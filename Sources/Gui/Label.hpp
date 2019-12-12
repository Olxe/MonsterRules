#pragma once

#include "Widget.hpp"

namespace gui
{
	class Label: public Widget
	{
	public:
		Label(const std::string& text, const sf::Font& font, unsigned int characterSize, sf::Uint32 style, const sf::Color& color, const sf::Vector2f& position);
		~Label();

		void setText(const std::string& text);

	private:
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	private:
		sf::Text m_label;

	};
}