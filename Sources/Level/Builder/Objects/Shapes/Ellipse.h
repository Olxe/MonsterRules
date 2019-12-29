#pragma once

#include "../ObjectTemplate.h"

namespace Builder
{
	class Ellipse: public ObjectTemplate
	{
	public:
		Ellipse(std::string name, std::string type, float x, float y, float width, float height, float rotation);
		~Ellipse();

	private:

	};
}


