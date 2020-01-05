#include "Polygone.h"

using namespace Builder;

Polygone::Polygone(Parser::ObjectNode* object, std::string points, PolygoneType category)
	: ObjectTemplate(object)
	, m_category(category)
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
		
		m_points.push_back(Point(sf::Vector2f(x, y)));
		token = strtok_s(NULL, " ", &next_token);
	}

	delete[] input;
}
