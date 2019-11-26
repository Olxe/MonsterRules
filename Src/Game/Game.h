#ifndef __GAME__
#define __GAME__

#include <SFML/Graphics.hpp>

class Game
{
public:
	Game();
	~Game();

	void StartGame();

private:
	void init();

private:
	sf::RenderWindow
};

#endif