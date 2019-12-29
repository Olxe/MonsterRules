#include "SceneObject.h"

using namespace Builder;

SceneObject::SceneObject(int uniqueId, std::string name, std::string type, float x, float y, float width, float height, float rotation, Tile* tile)
	: ObjectTemplate(name, type, x, y, width, height, rotation)
	, m_tile(tile)
	, m_uniqueId(uniqueId)
{
}

SceneObject::~SceneObject()
{
}