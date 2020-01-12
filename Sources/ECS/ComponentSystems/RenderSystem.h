#pragma once

#include "../EntitySystems/EntityComponentSystem.h"
#include "../Components/Cmp_render.h"
#include "../Components/Cmp_transform.h"


class RenderSystem : public ComponentSystem<Cmp_render, Cmp_transform>
{
	using BaseType = ComponentSystem<Cmp_render, Cmp_transform>;

public:
	RenderSystem(EntityManager* entityManager) : BaseType(entityManager) { }

	virtual void onUpdate(float dt) override;
};

