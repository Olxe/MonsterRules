#pragma once

#include "ObjectTemplate.h"
#include "Tile.h"

namespace Builder
{
	class SceneObject: public ObjectTemplate
	{
	public:
		SceneObject(Parser::ObjectNode* object, Tile* tile);
		~SceneObject();

		void SetTile(Tile* tile) { m_tile = tile; }
		Tile* GetTile() const { return m_tile; }

	private:
		Tile* m_tile;

	};
}

