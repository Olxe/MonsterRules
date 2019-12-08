#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

#include "../../Builder/TiledBuilder.h"

namespace layer
{
	class Layer
	{
	public:
		Layer();
		virtual ~Layer();

		virtual void Update(const float& deltaTime) = 0;
		virtual void Draw(sf::RenderWindow& window) = 0;

	private:

	};
}