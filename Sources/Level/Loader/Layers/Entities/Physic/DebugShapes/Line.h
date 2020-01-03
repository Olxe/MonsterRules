#pragma once

#include "DebugShape.h"

namespace debug
{
	class Line: public DebugShape
	{
	public:
		Line(std::unique_ptr<sf::VertexArray> shape);
		~Line();

		void setPosition(const sf::Vector2f& position, const float& rotation) override;

	private:
		std::unique_ptr<sf::VertexArray> m_shape;
		std::vector<sf::Vector2f> m_points;
	};
}

