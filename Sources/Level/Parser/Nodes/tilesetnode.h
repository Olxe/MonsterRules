#ifndef __TILESETNODE__
#define __TILESETNODE__

#include "Node.h"
#include "tilenode.h"
#include "propertiesnode.h"
#include "GridNode.h"

namespace Parser
{
	class TilesetNode: public Node
	{
	public:
		TilesetNode(int firstgid, std::string source, Node* parent = nullptr);
		~TilesetNode();

		int GetFirstgid() const { return m_firstgid; }
		std::string GetSource() const { return m_source; }
		std::string GetName() const { return m_name; }
		int GetTilewidth() const { return m_tilewidth; }
		int GetTileheight() const { return m_tileheight; }
		int GetTilecount() const { return m_tilecount; }
		int GetColums() const { return m_columns; }

	protected:
		void ParseAttribute(const tinyxml2::XMLElement* eAttribute) override;
		void ParseChildTag(const tinyxml2::XMLElement* eChild) override;

	private:
		int m_firstgid;
		std::string m_source;
		std::string m_name;
		int m_tilewidth;
		int m_tileheight;
		int m_tilecount;
		int m_columns;
	};
}

#endif