#pragma once

#include "../Object.h"

namespace Builder
{
	class Ellipse: public Object
	{
	public:
		Ellipse(std::string name, std::string type, float x, float y, float width, float height, float rotation);
		~Ellipse();

	private:

	};
}


