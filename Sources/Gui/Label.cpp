#include "Label.hpp"

namespace gui
{
	Label::Label(const std::string& text, const sf::Font& font, unsigned int characterSize, sf::Uint32 style, const sf::Color& color, const sf::Vector2f& position)
	{
		m_label.setString(text);
		m_label.setFont(font);
		m_label.setCharacterSize(characterSize);
		m_label.setStyle(style);
		m_label.setFillColor(color);

		sf::FloatRect r = m_label.getLocalBounds();
		m_label.setOrigin(r.left + std::round(r.width / 2.f), r.top + std::round(r.height / 2.f));
		m_label.setPosition(m_body.getPosition());

		this->setPosition(position);
	}

	Label::~Label()
	{
	}

	void Label::setPosition(const sf::Vector2f& position)
	{
		Widget::setPosition(position);
		m_label.setPosition(position);
	}

	void Label::setText(const std::string& text)
	{
		m_label.setString(text);
	}

	void Label::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		target.draw(m_label, states);
	}
}