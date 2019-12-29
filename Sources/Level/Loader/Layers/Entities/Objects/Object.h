#pragma once

#include "../Physic/PhysicalEntity.h"

namespace entities
{
	class Object: public PhysicalEntity
	{
	public:
		Object(Builder::SceneObject* obj);
		virtual ~Object();

		void onUpdate(const float& deltaTime) override;

	private:

	};
}

