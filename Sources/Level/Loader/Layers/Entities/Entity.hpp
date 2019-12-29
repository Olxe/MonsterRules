#pragma once

#include <SFML/Graphics.hpp>

#include "../../../Builder/Objects/SceneObject.h"
#include "../../../../Game/Window/AssetManager.hpp"

namespace entities
{
	class Entity: public sf::Sprite
	{
	public:
		Entity(Builder::SceneObject* obj);
		virtual ~Entity();

		virtual void onUpdate(const float& deltaTime) {}
		virtual void onDraw(sf::RenderWindow& window) const;
		
		int getId() const { return m_id; }
		std::string getType() const { return m_type; }
		std::string getName() const { return m_name; }

	private:
		void setup(sf::Vector2f position, sf::Vector2f size, float rotation);
		sf::Vector2f transformOffsetPoint(sf::Vector2f offset, float rotation);

	private:
		int m_id;
		std::string m_type;
		std::string m_name;

	};
}