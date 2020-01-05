#include "Line.h"
#include <iostream>
namespace debug
{
	Line::Line(std::unique_ptr<sf::VertexArray> shape)
		: DebugShape(shape.get())
		, m_shape(std::move(shape))
	{
		for (unsigned int i = 0; i < m_shape->getVertexCount(); ++i) {
			m_points.push_back(sf::Vector2f((*m_shape)[i].position));
		}
	}

	Line::~Line()
	{
	}

	void Line::setPosition(const sf::Vector2f& position)
	{
		for (unsigned int i = 0; i < m_shape->getVertexCount(); ++i) {
			(*m_shape)[i].position = m_points[i] + position;
		}
	}
}
