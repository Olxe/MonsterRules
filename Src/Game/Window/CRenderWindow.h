#ifndef __WINDOW__
#define __WINDOW__

#include <SFML/Graphics/RenderWindow.hpp>

#include "Settings.h"
#include "EventManager.h"

namespace Window
{
	class CRenderWindow : public sf::RenderWindow
	{
	private:
		CRenderWindow();
		~CRenderWindow();
	public:
		static CRenderWindow* GetInstance();

		void Init();
		void Update();

		bool GetIsWindowFocus() { return isWindowFocus; };
		float GetDeltaTime();

		void SetFPS(unsigned int fps);

	private:
		static CRenderWindow* m_instance;
		bool isWindowFocus;
		sf::Clock m_clockDeltaTime;
	};
}

#endif