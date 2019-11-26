#include "Object.h"

using namespace Builder;

Object::Object(std::string name, std::string type, float x, float y, float width, float height, float rotation)
	: m_name(name)
	, m_type(type)
	, m_x(x)
	, m_y(y)
	, m_width(width)
	, m_height(height)
	, m_rotation(rotation)
{
}

Object::~Object()
{
}

void Builder::Object::SetName(std::string name)
{
	m_name = name;
}

void Builder::Object::SetPosition(float x, float y)
{
	m_x = x;
	m_y = y;
}

void Builder::Object::SetSize(float width, float height)
{
	m_width = width;
	m_height = height;
}

void Builder::Object::SetRotation(float rotation)
{
	m_rotation = rotation;
}
