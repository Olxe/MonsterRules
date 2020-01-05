#pragma once

#include <SFML/Graphics.hpp>

namespace debug
{
	class DebugShape: public sf::Drawable
	{
	public:
		DebugShape(sf::Drawable* drawable);
		virtual ~DebugShape();

		virtual void setPosition(const sf::Vector2f& position) = 0;

	protected:
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	protected:
		sf::Drawable* m_drawable;
	};
}

