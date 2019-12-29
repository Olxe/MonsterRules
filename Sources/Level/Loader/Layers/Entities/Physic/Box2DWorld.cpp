#include "Box2DWorld.h"

Box2DWorld::Box2DWorld()
	: m_world(nullptr)
{
	m_world = new b2World(b2Vec2(0, 0));
	std::cout << "World created" << std::endl;
}

Box2DWorld::~Box2DWorld()
{
	if (m_world) delete m_world;
	std::cout << "World destroyed" << std::endl;
}