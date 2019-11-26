#pragma once

#include "Nodes/mapnode.h"

namespace Parser
{
	class TiledParser
	{
	public:
		TiledParser();
		~TiledParser();

		MapNode* ParseTMX(std::string directory, std::string fileName);

	private:
		MapNode* m_map;

	};
}


