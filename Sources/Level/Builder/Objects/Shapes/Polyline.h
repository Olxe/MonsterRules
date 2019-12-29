#pragma once

#include "../ObjectTemplate.h"
#include "Point.h"

namespace Builder
{
	class Polyline: public ObjectTemplate
	{
	public:
		Polyline(std::string name, std::string type, float x, float y, float rotation, std::string points);
		~Polyline();

	private:
		void convertPoints(std::string points);

	private:
		std::vector< Point > m_points;

	};
}

