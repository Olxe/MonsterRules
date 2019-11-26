#pragma once

#include "../Object.h"

namespace Builder
{
	class Point: public Object
	{
	public:
		Point(std::string name, std::string type, float x, float y);
		~Point();

	private:

	};
}


