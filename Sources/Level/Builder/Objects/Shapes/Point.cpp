#include "Point.h"

using namespace Builder;

Point::Point(Parser::ObjectNode* object)
	: ObjectTemplate(object)
	, m_position(sf::Vector2f())
{
}

Builder::Point::Point(sf::Vector2f position)
	: ObjectTemplate(nullptr)
	, m_position(position)
{
}

Point::~Point()
{
}

sf::Vector2f Builder::Point::getPosition() const
{
	if (m_object) {
		return ObjectTemplate::getPosition();
	}

	return m_position;
}
