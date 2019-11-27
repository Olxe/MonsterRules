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
		bool WindowFocus() const;

	private:
		bool isWindowFocus;
		sf::Clock m_clockDeltaTime;
	};
}

#endif