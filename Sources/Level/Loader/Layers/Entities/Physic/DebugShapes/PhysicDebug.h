#pragma once

#include <Box2D/Box2D.h>

#include "Shape.h"
#include "Line.h"

namespace debug
{
	class PhysicDebug
	{
	public:
		PhysicDebug(float scaling);
		virtual ~PhysicDebug();

		void onUpdate();
		void onDraw(sf::RenderWindow& window);

	protected:
		void setBody(b2Body* body) { m_body = body; }

		void addShape(std::unique_ptr<sf::Shape> shape, const sf::Vector2f& offset);
		void addShape(std::unique_ptr<sf::VertexArray> shape);

	private:
		std::vector<std::unique_ptr<DebugShape>> m_shapes;

		b2Body* m_body;
		float m_scale;
	};
}

