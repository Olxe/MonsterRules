#ifndef __CVERTEXARRAY__
#define __CVERTEXARRAY__

#include <SFML/Graphics.hpp>
#include "../../../../Game/Window/AssetManager.hpp"

namespace layer
{
	class CVertexArray : public sf::Drawable, public sf::Transformable
	{
	public:
		CVertexArray(const std::string& source, const sf::Vector2i& tilemapSize);
		virtual ~CVertexArray();

		bool Load(const std::string& source, const sf::Vector2i& tilemapSize);

	private:
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	private:
		sf::Texture* m_texture;
		sf::VertexArray m_vertexArray;
	};
}

#endif