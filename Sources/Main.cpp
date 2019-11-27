#include "Game/Game.h"

int main(void)
{
	int cpt = 1;

	while(cpt > 0){

		Game game;
		game.StartGame();
		
		cpt--;
		//std::cout << cpt << std::endl;
	}

	return 0;
}

/*todo

- InputManager

*/