#pragma once

#include "../../Parser/Nodes/objectnode.h"

#include "../Objects/Shapes/Ellipse.h"
#include "../Objects/Shapes/Point.h"
#include "../Objects/Shapes/Polygone.h"

namespace Builder
{
	class ObjectBuilder
	{
	public:
		ObjectBuilder();
		~ObjectBuilder();

		static std::unique_ptr<ObjectTemplate> BuildObject(Parser::ObjectNode* objectNode);

	};
}

