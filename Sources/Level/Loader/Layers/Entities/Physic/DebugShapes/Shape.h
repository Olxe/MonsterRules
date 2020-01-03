#pragma once

#include "DebugShape.h"

namespace debug
{
	class Shape: public DebugShape
	{
	public:
		Shape(std::unique_ptr<sf::Shape> shape, const sf::Vector2f& offset);
		~Shape();

		void setPosition(const sf::Vector2f& position, const float& rotation) override;

	private:
		std::unique_ptr<sf::Shape> m_shape;
		sf::Vector2f m_offset;

	};
}

