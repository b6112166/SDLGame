#include "Engine.h"
using namespace std;




Engine::Engine() 
{
	isRunning = false;
}

Engine::~Engine() 
{
	clean();
}

void Engine::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) 
{

	Uint32 flags = 0;
	if (fullscreen)
		flags |= SDL_WINDOW_FULLSCREEN;
	//system init
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_EVENTS) < 0) 
	{
		cout << "SDL initialization failed";
		isRunning = false;

	}
	else
	{
		std::cout << "SDL initalized";
		//window create
		gameWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (gameWindow == nullptr) 
		{
			cout << "window creation failed!";
			isRunning = false;
		}
		else {
			cout << "window created!";

			renderer = SDL_CreateRenderer(gameWindow,-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
			if (renderer == nullptr) 
			{
				cout << "renderer failed to initialize";
				isRunning = false;
			}
			else 
			{
				cout << "renderer initialized!";
				isRunning = true;
			}

			SDL_Surface* tempSurface = IMG_Load("assets/characters.png");
			playerTexture = SDL_CreateTextureFromSurface(renderer, tempSurface);

			playerRect


		}
	}
}

bool Engine::running() {
	return isRunning;
}

void Engine::handleEvents()
{
	SDL_Event e;
	while(SDL_PollEvent(&e)!=0) {
		switch (e.type) {
			case SDL_QUIT:
				isRunning = false;
			case SDL_KEYDOWN: 

				//movement
				if (e.key.keysym.sym == SDLK_w) 
				{
					mainPlayer->moveVertical(true);
				}
				else if (e.key.keysym.sym == SDLK_s) 
				{
					mainPlayer->moveVertical(false);
				}
				else if (e.key.keysym.sym == SDLK_a) 
				{
					mainPlayer->moveHorizontal(false);
				}
				else if (e.key.keysym.sym == SDLK_d) 
				{
					mainPlayer->moveHorizontal(true);
				}

				break;
				
			
				
			default:
				break;

		}
	}

}

void Engine::update()
{


}

void Engine::render()
{
	//clear everything
	SDL_RenderClear(renderer);

	
	SDL_RenderCopy(renderer, playerTexture, NULL, playerRect);//player render

	//draw
	SDL_RenderPresent(renderer);

}

void Engine::clean()
{
	SDL_DestroyWindow(gameWindow);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	cout << "Game exited,cya!"<<endl;
}
