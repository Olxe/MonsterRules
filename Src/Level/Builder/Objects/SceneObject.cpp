#include "SceneObject.h"

using namespace Builder;

SceneObject::SceneObject(std::string name, std::string type, float x, float y, float width, float height, float rotation, Tile* tile)
	: Object(name, type, x, y, width, height, rotation)
	, m_tile(tile)
{
}

SceneObject::~SceneObject()
{
}