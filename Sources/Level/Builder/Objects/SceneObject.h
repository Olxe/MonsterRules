#pragma once

#include "ObjectTemplate.h"
#include "Tile.h"

namespace Builder
{
	class SceneObject: public ObjectTemplate
	{
	public:
		SceneObject(int uniqueId, std::string name, std::string type, float x, float y, float width, float height, float rotation, Tile* tile);
		~SceneObject();

		void SetTile(Tile* tile) { m_tile = tile; }
		Tile* GetTile() const { return m_tile; }
		int getUniqueId() const { return m_uniqueId; }

	private:
		Tile* m_tile;
		int m_uniqueId;

	};
}

