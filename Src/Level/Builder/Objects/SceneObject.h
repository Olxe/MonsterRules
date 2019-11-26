#pragma once

#include "Object.h"
#include "Tile.h"

namespace Builder
{
	class SceneObject: public Object
	{
	public:
		SceneObject(std::string name, std::string type, float x, float y, float width, float height, float rotation, Tile* tile);
		~SceneObject();

		void SetTile(Tile* tile) { m_tile = tile; }
		Tile* GetTile() const { return m_tile; }

	private:
		Tile* m_tile;

	};
}

