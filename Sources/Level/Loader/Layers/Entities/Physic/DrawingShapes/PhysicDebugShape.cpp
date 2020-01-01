#include "PhysicDebugShape.h"

PhysicDebugShape::PhysicDebugShape(std::unique_ptr<sf::Shape> shape, sf::Vector2f offset)
	: m_shape(std::move(shape))
	, m_offset(offset)
{
}

PhysicDebugShape::~PhysicDebugShape()
{
}
