#include "ObjectTemplate.h"

using namespace Builder;

ObjectTemplate::ObjectTemplate(std::string name, std::string type, float x, float y, float width, float height, float rotation)
	: m_name(name)
	, m_type(type)
	, m_x(x)
	, m_y(y)
	, m_width(width)
	, m_height(height)
	, m_rotation(rotation)
{
}

ObjectTemplate::~ObjectTemplate()
{
}

void Builder::ObjectTemplate::SetName(std::string name)
{
	m_name = name;
}

void Builder::ObjectTemplate::SetPosition(float x, float y)
{
	m_x = x;
	m_y = y;
}

void Builder::ObjectTemplate::SetSize(float width, float height)
{
	m_width = width;
	m_height = height;
}

void Builder::ObjectTemplate::SetRotation(float rotation)
{
	m_rotation = rotation;
}
