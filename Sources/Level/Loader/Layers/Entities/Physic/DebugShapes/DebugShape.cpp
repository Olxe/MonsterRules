#include "DebugShape.h"

namespace debug
{
	DebugShape::DebugShape(sf::Drawable* drawable)
		: m_drawable(drawable)
	{
	}

	DebugShape::~DebugShape()
	{
	}

	void DebugShape::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		if (m_drawable) {
			target.draw(*m_drawable, states);
		}
	}
}