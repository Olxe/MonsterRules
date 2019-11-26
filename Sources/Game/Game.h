#ifndef __GAME__
#define __GAME__

#include <SFML/Graphics.hpp>

#include "../Level/LevelManager.h"

#include "Window/CRenderWindow.h"

class Game
{
public:
	Game();
	~Game();

	void StartGame();

private:
	void init();

private:
	
};

#endif