#pragma once

#include <SFML/Graphics.hpp>

#include "../../../Builder/Objects/SceneObject.h"
#include "../../../../Game/Window/AssetManager.hpp"

namespace entities
{
	class Entity: public sf::RectangleShape
	{
	public:
		Entity(Builder::Object* obj, int id);
		virtual ~Entity();

		virtual void onUpdate(const float& deltaTime);
		virtual void onDraw(sf::RenderWindow& window);

	protected:
		sf::Vector2f transformOffsetPoint(sf::Vector2f offset, float rotation);

	private:
		int m_id;
		std::string m_type;
		std::string m_name;
	};
}