#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class PhysicDebugShape
{
public:
	PhysicDebugShape(std::unique_ptr<sf::Shape> shape, sf::Vector2f offset);
	~PhysicDebugShape();
	
	const sf::Vector2f& getOffset() const { return m_offset; }
	sf::Shape* getBody() { return m_shape.get(); }

private:
	std::unique_ptr<sf::Shape> m_shape;

	sf::Vector2f m_offset;

};

