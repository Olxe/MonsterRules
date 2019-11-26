#include "Ellipse.h"

using namespace Builder;

Ellipse::Ellipse(std::string name, std::string type, float x, float y, float width, float height, float rotation)
	: Object(name, type, x, y, width, height, rotation)
{
}

Ellipse::~Ellipse()
{
}