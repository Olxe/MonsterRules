#include "PhysicDebug.h"

namespace debug
{
	PhysicDebug::PhysicDebug(float scaling)
		: m_body(nullptr)
		, m_scale(scaling)
	{
	}

	PhysicDebug::~PhysicDebug()
	{
	}

	void PhysicDebug::onUpdate()
	{
		if (m_body) {
			for (auto& it : m_shapes) {
				it->setPosition(sf::Vector2f(m_body->GetPosition().x * m_scale, m_body->GetPosition().y * m_scale), m_body->GetAngle() * 180.f / 3.14f);
			}
		}
	}

	void PhysicDebug::onDraw(sf::RenderWindow& window)
	{
		if (m_body) {
			sf::Transform transform;
			transform.rotate(m_body->GetAngle() * 180.f / 3.14f, sf::Vector2f(m_body->GetPosition().x * m_scale, m_body->GetPosition().y * m_scale));
			for (auto& it : m_shapes) {
				window.draw(*it, transform);
			}
		}
	}

	void PhysicDebug::addShape(std::unique_ptr<sf::Shape> shape, const sf::Vector2f& offset)
	{
		m_shapes.push_back(std::unique_ptr<Shape>(new Shape(std::move(shape), offset)));
	}

	void PhysicDebug::addShape(std::unique_ptr<sf::VertexArray> shape)
	{
		m_shapes.push_back(std::unique_ptr<Line>(new Line(std::move(shape))));
	}
}
