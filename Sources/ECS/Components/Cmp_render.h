#pragma once

#include <SFML/System/Vector2.hpp>

#include "../EntitySystems/EntityComponent.h"

class Cmp_render : public EntityComponent
{
public:
	Cmp_render() {}
	~Cmp_render() override = default;

	bool onInit(void* data) override {}

private:

};

