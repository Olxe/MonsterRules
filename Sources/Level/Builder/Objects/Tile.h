#pragma once

#include <vector>

#include "../../../Tools/ToolsFunction.h"
#include "../../Parser/Nodes/tilenode.h"

#include "ObjectBuilder.h"

namespace Builder
{
	class Tile
	{
	public:
		Tile(int gid, Parser::TileNode* tile, std::string templateDirectory);
		virtual ~Tile();

		int getGid() const { return m_gid; }
		std::string getType() const;
		Parser::PropertyNode getProperty(std::string name) const;
		const std::vector< std::unique_ptr<ObjectTemplate> >& getObjects() const { return m_objects; }
		virtual int getId() const;
		virtual std::string getSource() const;
		virtual sf::Vector2f getSize() const;
		 
		void setSource(std::string source);
		void setSize(sf::Vector2f size);
		void setTile(Parser::TileNode* tile);

	protected:
		int m_gid;
		Parser::TileNode* m_tile;
		std::vector< std::unique_ptr<ObjectTemplate> > m_objects;
		std::string m_templateDirectory;
		std::string m_source;
		sf::Vector2f m_size;
	};

}
