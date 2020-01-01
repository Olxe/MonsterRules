#include "PhysicDebug.h"

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
			it->getBody()->setPosition(sf::Vector2f(m_body->GetPosition().x * m_scale + it->getOffset().x, m_body->GetPosition().y * m_scale + it->getOffset().y));
		}
	}
}

void PhysicDebug::onDraw(sf::RenderWindow& window)
{
	for (auto& it : m_shapes) {
		sf::Transform transform;
		transform.rotate(m_body->GetAngle() * 180.f / 3.14f, sf::Vector2f(m_body->GetPosition().x * m_scale, m_body->GetPosition().y * m_scale));
		window.draw(*it->getBody(), transform);
	}

	for (auto& it : m_lines) {//
		sf::Transform transform;
		transform.rotate(m_body->GetAngle() * 180.f / 3.14f, sf::Vector2f(m_body->GetPosition().x * m_scale, m_body->GetPosition().y * m_scale));
		window.draw(it, transform);
	}
}

void PhysicDebug::addRect(std::unique_ptr<sf::Shape> shape, sf::Vector2f offset)
{
	m_shapes.push_back(std::unique_ptr<PhysicDebugShape>(new PhysicDebugShape(std::move(shape), offset)));
}

void PhysicDebug::addLine(sf::Vector2f p1, sf::Vector2f p2, sf::Vector2f offset)
{
}
