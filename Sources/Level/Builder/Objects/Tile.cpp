#include "Tile.h"

using namespace Builder;

Tile::Tile(int id, int gid, std::string source, float width, float height)
	: m_image(source, width, height)
	, m_id(id)
	, m_gid(gid)
{

}

Tile::~Tile()
{
	clearVector(m_objects);
}
