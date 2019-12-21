#pragma once

#include "../Entity.hpp"
#include "../../../../../Game/Window/WindowManager.hpp"

namespace entities 
{
	class Archer: public Entity
	{
	public:
		Archer(Builder::Object* obj, int id);
		~Archer();

		void onUpdate(const float& deltaTime) override;
		void onDraw(sf::RenderWindow& window) override;

	private:
		void input(const float& deltaTime);

	};
}

