#pragma once

#include "../Object.h"
#include "Point.h"

namespace Builder
{
	class Polygone: public Object
	{
	public:
		Polygone(std::string name, std::string type, float x, float y, float rotation, std::string points);
		~Polygone();

	private:
		void convertPoints(std::string points);

	private:
		std::vector< Point > m_points;
	};
}


