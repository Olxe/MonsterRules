#include "Point.h"

using namespace Builder;

Point::Point(std::string name, std::string type, float x, float y)
	: Object(name, type, x, y, 0.f, 0.f, 0.f)
{
}

Point::~Point()
{
}