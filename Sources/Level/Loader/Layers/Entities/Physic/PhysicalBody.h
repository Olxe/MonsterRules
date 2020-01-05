#pragma once

#include <SFML/Graphics.hpp>

#include "Box2DWorld.h"

#include "DebugShapes/Shape.h"
#include "DebugShapes/Line.h"

enum class Hitbox
{
	ANY = 0x0000,
	PLAYER_SENSOR = 0x0001,
	PLAYER_PHYSICAL = 0x0002,
	PHYSICAL = 0x0004,
	SENSOR = 0x0008
};

class PhysicalBody
{
public:
	PhysicalBody(sf::Vector2f position, float rotation, b2BodyType bodyType, bool rotationFixed, void* userData);
	~PhysicalBody();

	void onUpdate();
	void onDebugDraw(sf::RenderWindow& window);

	void Create(sf::Vector2f position, float rotation, b2BodyType bodyType, bool rotationFixed, void* userData);
	bool AddFixtureRectangle(sf::Vector2f offset, sf::Vector2f size, float rotation, float density = 1.f, bool isSensor = false);
	bool AddFixtureEdge(sf::Vector2f offset, sf::Vector2f p1, sf::Vector2f p2, float density = 1.f, bool isSensor = false);
	bool AddFixtureCircle(sf::Vector2f offset, float radius, float density = 1.f, bool isSensor = false);
	bool AddFixturePolygon(sf::Vector2f offset, std::vector<sf::Vector2f> points, float density = 1.f, bool isSensor = false);

	sf::Vector2f getPosition() const;
	float getRotation() const;
	b2Body* getBody() { return m_b2Body; }

private:
	void clearBody();

private:
	const float SCALE;
	b2Body* m_b2Body;
	std::vector<std::unique_ptr<debug::DebugShape>> m_shapes;
	sf::Transform m_transform;

};


