#include "Game/Game.h"
#include "Tools/Signal.h"
void DisplayString(std::string const& str)
{
	std::cout << "Displayed: " << str << std::endl;
}
int main(void)
{
	int cpt = 1;
	//Signal<void(std::string const&)> Out;

	//Out.Connect(DisplayString);
	//Out("Bonjour tout le monde !");
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
- NextState test before update (idem for lastState ?)

*/