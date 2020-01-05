#include "SceneObject.h"

using namespace Builder;

SceneObject::SceneObject(Parser::ObjectNode* object, Tile* tile)
	: ObjectTemplate(object)
	, m_tile(tile)
{
}

SceneObject::~SceneObject()
{
}