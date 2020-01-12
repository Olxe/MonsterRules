#pragma once

#include <SFML/System/Vector2.hpp>

#include "../EntitySystems/EntityComponent.h"

class Cmp_transform : public EntityComponent
{
public:
	Cmp_transform() : m_position(), m_scaling(1, 1), m_size(), m_rotation(0) {}
	~Cmp_transform() override = default;

	bool onInit(void* data) override {}

private:
	sf::Vector2f m_position;
	sf::Vector2f m_scaling;
	sf::Vector2f m_size;
	float m_rotation;
};

