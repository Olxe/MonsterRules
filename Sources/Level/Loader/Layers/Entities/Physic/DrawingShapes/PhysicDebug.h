#pragma once

#include <Box2D/Box2D.h>

#include "PhysicDebugShape.h"

class PhysicDebug
{
public:
	PhysicDebug(float scaling);
	~PhysicDebug();

	void onUpdate();
	void onDraw(sf::RenderWindow& window);

protected:
	void addRect(std::unique_ptr<sf::Shape> shape, sf::Vector2f offset);
	void setBody(b2Body* body) { m_body = body; }

	void addLine(sf::Vector2f p1, sf::Vector2f p2, sf::Vector2f offset);

private:
	std::vector<std::unique_ptr<PhysicDebugShape>> m_shapes;

	std::vector<sf::VertexArray> m_lines;
	b2Body* m_body;
	float m_scale;
};

