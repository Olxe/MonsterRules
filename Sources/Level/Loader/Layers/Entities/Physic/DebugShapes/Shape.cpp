#include "Shape.h"

namespace debug
{
	Shape::Shape(std::unique_ptr<sf::Shape> shape, const sf::Vector2f& offset)
		: DebugShape(shape.get())
		, m_shape(std::move(shape))
		, m_offset(offset)
	{
	}

	Shape::~Shape()
	{
	}

	void Shape::setPosition(const sf::Vector2f& position, const float& rotation)
	{
		m_shape->setPosition(m_offset + position);
	}
}
