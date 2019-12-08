#include "CVertexArray.hpp"

namespace layer
{
	CVertexArray::CVertexArray(const std::string& source, const sf::Vector2i& tilemapSize)
		: m_texture(nullptr)
	{
	}

	CVertexArray::~CVertexArray()
	{
	}

	bool CVertexArray::Load(const std::string& source, const sf::Vector2i& tilemapSize)
	{
		m_texture = AssetManager::Instance()->GetTexture(source);
		m_vertexArray.setPrimitiveType(sf::Quads);
		m_vertexArray.resize(tilemapSize.x * tilemapSize.y * 4);

		return m_texture;
	}

	void CVertexArray::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		if (m_texture) {
			states.transform *= getTransform();
			states.texture = m_texture;
			target.draw(m_vertexArray, states);
		}
	}
}