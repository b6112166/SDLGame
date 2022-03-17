#include "SDL/SDL.h"
#include <iostream>
#include "Engine.h"
using namespace std;
//variables for capped 60fps
const int MAXFPS = 60;
const int FRAMEDELAY = 1000 / MAXFPS;

const int WIDTH = 800;
const int HEIGHT = 600;

int main(int argc, char* args[])
{

	Uint32 frameStart;
	int frameTime;

	Engine* myGame = nullptr;
	myGame = new Engine();

	myGame->init("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, false);

	

	while (myGame->running()) 
	{

		frameStart = SDL_GetTicks();

		myGame->handleEvents();
		myGame->update();
		myGame->render();
		frameTime = SDL_GetTicks() - frameStart;
		
		if (FRAMEDELAY > frameTime)
		{
			SDL_Delay(FRAMEDELAY - frameTime);
		}
	}

	myGame->clean();
	
	return 0;
}