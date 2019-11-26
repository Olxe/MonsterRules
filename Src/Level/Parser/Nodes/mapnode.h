#ifndef __MAPNODE__
#define __MAPNODE__

#include "Node.h"
#include "tilesetnode.h"
#include "objectgroupnode.h"
#include "layernode.h"

namespace Parser
{
	class MapNode: public Node
	{
	public:
		MapNode(std::string TMXDirectory, Node* parent = nullptr);
		~MapNode();

		int GetWidth() const { return m_width; }
		int GetHeight() const { return m_height; }
		int GetTilewidth() const { return m_tilewidth; }
		int GetTileheight() const { return m_tileheight; }
		bool GetIsInfinite() const { return isInfinite; }
		std::string GetDirectory() const { return m_directory; }

	protected:
		void ParseAttribute(const tinyxml2::XMLElement* eAttribute) override;
		void ParseChildTag(const tinyxml2::XMLElement* eChild) override;

	private:
		void parseTileset(const tinyxml2::XMLElement* eTileset);

	private:
		int m_width;
		int m_height;
		int m_tilewidth;
		int m_tileheight;
		bool isInfinite;
		std::string m_directory;
	};
}

#endif