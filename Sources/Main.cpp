#include "Game/Game.h"

int main(void)
{
	int cpt = 1;

	while(cpt > 0){

		Game game;
		game.Run();
		
		cpt--;
		//std::cout << cpt << std::endl;
	}

	//while(1){}

	return 0;
}

/*todo

- InputManager -> bindings by settings
- isReplacing -> keep instance if true, delete if false

*/