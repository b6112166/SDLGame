#include "Engine.h"
using namespace std;

extern enum direciton
{

};


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

			SDL_Surface* tempSurface = IMG_Load("assets/ball.png");
			playerTexture = SDL_CreateTextureFromSurface(renderer, tempSurface);
			SDL_Rect  tempRect = { 0,0, tempSurface->w ,tempSurface->h };

			playerRect = new SDL_Rect( tempRect );

			
			SDL_FreeSurface(tempSurface);
			tempSurface = nullptr;


			mainPlayer = new Player();

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
			/*case SDL_KEYDOWN:

				
				if (e.key.keysym.sym == SDLK_w) 
				{
					mainPlayer->move(d_up);
				}
				else if (e.key.keysym.sym == SDLK_s) 
				{
					mainPlayer->move(d_down);
				}
				else if (e.key.keysym.sym == SDLK_a) 
				{
					mainPlayer->move(d_left);
				}
				else if (e.key.keysym.sym == SDLK_d) 
				{
					mainPlayer->move(d_right);
				}
				
				break;
				
			
			*/

			default:
				break;

		}
	}
	//movement

	const Uint8* state = SDL_GetKeyboardState(NULL);
	//check diagonals first
	if (state[SDL_SCANCODE_W]&&state[SDL_SCANCODE_A]) 
	{
		mainPlayer->move(d_upleft);
	}
	else if (state[SDL_SCANCODE_W] && state[SDL_SCANCODE_D]) 
	{
		mainPlayer->move(d_upright);
	}
	else if (state[SDL_SCANCODE_S] && state[SDL_SCANCODE_A]) 
	{
		mainPlayer->move(d_downleft);
	}
	else if (state[SDL_SCANCODE_S] && state[SDL_SCANCODE_D]) 
	{
		mainPlayer->move(d_downright);
	}
	else {
		//check singular
		if (state[SDL_SCANCODE_W]) 
		{
			mainPlayer->move(d_up);
		}
		else if (state[SDL_SCANCODE_A])
		{
			mainPlayer->move(d_left);
		}
		else if (state[SDL_SCANCODE_D])
		{
			mainPlayer->move(d_right);
		}
		else if (state[SDL_SCANCODE_S])
		{
			mainPlayer->move(d_down);
		}

	}



}

void Engine::update()
{

	playerRect->x = mainPlayer->getPosX();
	playerRect->y = mainPlayer->getPosY();
}

void Engine::render()
{
	//clear everything
	
	

	SDL_RenderClear(renderer);

	
	SDL_SetRenderDrawColor(renderer, 255, 2555, 255, 255);
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
