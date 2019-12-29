#include "Tile.h"

using namespace Builder;

Tile::Tile(int id, int gid, std::string source, float width, float height)
	: m_source(source)
	, m_width(width)
	, m_height(height)
	, m_id(id)
	, m_gid(gid)
{

}

Tile::~Tile()
{
	clearVector(m_objects);
}

void Builder::Tile::setSize(float w, float h)
{
	m_width = w;
	m_height = h;
}
