#ifndef __WINDOW__
#define __WINDOW__

#include <SFML/Graphics/RenderWindow.hpp>

//#include "Settings.h"
//#include "EventManager.h"
#include "../../Tools/Singleton.h"
#include "../../Tools/ToolsFunction.h"

namespace Window
{
	class CRenderWindow : public sf::RenderWindow, public Singleton< CRenderWindow >
	{
		friend class Singleton< CRenderWindow >;

	private:
		CRenderWindow();
		~CRenderWindow();

	public:
		float DeltaTime();
		bool WindowFocus();

		void Init();
		void Update();
		
		void SetFPS(unsigned int fps);

	private:
		bool isWindowFocus;
		sf::Clock m_clockDeltaTime;
	};
}

#endif