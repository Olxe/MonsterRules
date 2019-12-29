#pragma once

#include "Hero.h"

namespace entities 
{
	class Archer: public Hero
	{
	public:
		Archer(Builder::SceneObject* obj);
		~Archer();

	};
}

