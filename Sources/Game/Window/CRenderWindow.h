#ifndef __WINDOW__
#define __WINDOW__

#include <SFML/Graphics/RenderWindow.hpp>

#include "Settings.h"

namespace Window
{
	class CRenderWindow: public sf::RenderWindow
	{
	public:
		CRenderWindow();
		~CRenderWindow();

		void Create(Settings& settings);
		void SetWindowFocus(bool value);
		bool IsFocus() const;

		void setDefaultView();
		void setGameView();

	private:
		bool m_focusing;
		sf::Vector2u m_size;
		sf::View m_gameView;
	};
}

#endif