#ifndef __GAME__
#define __GAME__

#include "../Game/Window/WindowManager.hpp"

#include "../GameEngine/GameEngine.hpp"
#include "../GameEngine/States/MainMenuState.hpp"

class Game
{
public:
	Game();
	~Game();

	void Run();

};

#endif