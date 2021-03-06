
#include "Game.h"
#include <memory>

//lets us use the gpu
extern "C" {
	__declspec(dllexport) unsigned long NvOptimusEnablement = 0x01;
	__declspec(dllexport) int AmdPowerXpressRequestHighPerformance = 0x01;
}

int main()
{
	//Game* myGame = new Game("Evyn's Terrible Game",1600,900);
	std::shared_ptr<Game> myGame = std::make_shared<Game>("Evyn's Terrible Game", 1600, 900);
	
	myGame->init();

	myGame->runGame();

	std::cout<< "Game has exited!" <<std::endl;


	return 0;
}