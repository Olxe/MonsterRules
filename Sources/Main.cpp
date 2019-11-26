#include "Game/Game.h"

int main(void)
{
	int cpt = 50000;

	while(cpt > 0){

		Game game;
		game.StartGame();
		
		cpt--;
		//std::cout << cpt << std::endl;
	}

	while(true){}

	return 0;
}