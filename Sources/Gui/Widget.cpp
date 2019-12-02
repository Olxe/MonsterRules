#include "Widget.hpp"

namespace gui
{
	Widget::Widget()
		: MouseButtonReleasedCallback( [&]() { void(); } )
	{
	}

	Widget::~Widget()
	{
	}
	void Widget::setPosition(const sf::Vector2f& position)
	{
		m_body.setPosition(position);
		m_position = position;
	}
}