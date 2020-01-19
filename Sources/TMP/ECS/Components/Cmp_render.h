#pragma once

#include <SFML/Graphics.hpp>

#include "../EntitySystems/EntityComponent.h"

class Cmp_render : public EntityComponent
{
public:
	Cmp_render(sf::Texture* texture) : m_texture(texture) {}
	~Cmp_render() override = default;

	bool onInit(void* data) override {}

	void onDraw(sf::RenderWindow& window) { window.draw(m_sprite); }

private:
	sf::Sprite m_sprite;
	sf::Texture* m_texture;
};

