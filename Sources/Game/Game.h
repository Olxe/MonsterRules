#ifndef __GAME__
#define __GAME__

#include "../Level/LevelManager.h"
#include "Window/WindowManager.hpp"

#include "GameEngine/GameEngine.hpp"
#include "GameEngine/MainMenuState.hpp"

class Game
{
public:
	Game();
	~Game();

	void Run();

};

#endif