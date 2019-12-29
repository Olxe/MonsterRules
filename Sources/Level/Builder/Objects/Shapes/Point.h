#pragma once

#include "../ObjectTemplate.h"

namespace Builder
{
	class Point: public ObjectTemplate
	{
	public:
		Point(std::string name, std::string type, float x, float y);
		~Point();

	private:

	};
}


