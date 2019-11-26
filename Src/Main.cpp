#include "Level/LevelManager.h"

int main(void)
{
	int cpt = 1;

	while(cpt > 0){
		LevelManager levelManager;
		levelManager.LoadLevel(Level::LEVEL_1);
		
		cpt--;
		std::cout << cpt << std::endl;
	}

	return 0;
}