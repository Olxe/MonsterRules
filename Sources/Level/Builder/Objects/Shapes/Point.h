#pragma once

#include "../ObjectTemplate.h"

namespace Builder
{
	class Point: public ObjectTemplate
	{
	public:
		Point(Parser::ObjectNode* object);
		Point(sf::Vector2f position);
		~Point();

		sf::Vector2f getPosition() const override;

	private:
		sf::Vector2f m_position;

	};
}


