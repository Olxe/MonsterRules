#pragma once

#include "../../../../../Tools/Singleton.hpp"
#include <Box2D/Box2D.h>
#include <iostream>

class Box2DWorld: public Singleton<Box2DWorld>
{
	friend class Singleton<Box2DWorld>;

private:
	Box2DWorld();
	~Box2DWorld();

public:
	b2World* getWorld() { return m_world; }

private:
	b2World* m_world;

};

