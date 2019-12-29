#include "Object.h"

namespace entities
{
	Object::Object(Builder::SceneObject* obj)
		: PhysicalEntity(obj)
	{
	}

	Object::~Object()
	{
	}

	void Object::onUpdate(const float& deltaTime)
	{
		PhysicalEntity::onUpdate(deltaTime);
	}
}
