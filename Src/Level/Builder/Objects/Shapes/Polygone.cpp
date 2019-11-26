#include "Polygone.h"

using namespace Builder;

Polygone::Polygone(std::string name, std::string type, float x, float y, float rotation, std::string points)
	: Object(name, type, x, y, 0.f, 0.f, rotation)
{
	this->convertPoints(points);
}

Polygone::~Polygone()
{
}

void Builder::Polygone::convertPoints(std::string points)
{
	char* input = new char[points.length() + 1];
	strcpy_s(input, points.length() + 1, points.c_str());
	
	const char* delim = " ";
	char* next_token = nullptr;
	char* token = strtok_s(input, delim, &next_token);

	while (token) {
		float x;
		float y;
		sscanf_s(token, "%f,%f", &x, &y);
		
		m_points.push_back(Point("", "", x, y));
		token = strtok_s(NULL, " ", &next_token);
	}

	delete[] input;
}
