#pragma once

#include "../../Parser/Nodes/objectgroupnode.h"
#include "Layout.h"

#include "../Objects/SceneObject.h"
#include "../Objects/Shapes/Ellipse.h"
#include "../Objects/Shapes/Point.h"
#include "../Objects/Shapes/Polygone.h"
#include "../Objects/Shapes/Polyline.h"

namespace Builder
{
	class ObjectGroupBuilder: public Layout
	{
	public:
		ObjectGroupBuilder(Parser::ObjectGroupNode* objectGroup, std::vector< Tile* >& tiles);
		~ObjectGroupBuilder();

	private:
		std::vector< Object* > m_layout;

	};
}
