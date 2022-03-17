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

			

			//texture loader code
			IMG_Init(IMG_INIT_PNG);
			
			playerTexture = textureLoader("assets/ball.png");
		

			playerRect.h = 20;
			playerRect.w = 20;

			
			
			


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

				//keyboard controls (keydown)
			
			

			default:
				break;

		}
	}
	//movement
	/**/
	// Get state of keyboard
	const Uint8* state = SDL_GetKeyboardState(NULL);
	
	if ((!state[SDL_SCANCODE_A] && !state[SDL_SCANCODE_D])||(state[SDL_SCANCODE_A]&&state[SDL_SCANCODE_D]))//not moving
	{
		mainPlayer->stop();
	}
	else
	{
		if (state[SDL_SCANCODE_A]) 
		{
			mainPlayer->walk(direction::d_left);
		}
		//left 
		else if (state[SDL_SCANCODE_D]) 
		{
			mainPlayer->walk(direction::d_right);
		}
		//right

		
	}
	if (state[SDL_SCANCODE_SPACE])
	{
		mainPlayer->jump();
		cout << "jumpping";
	}
	//jump

}

void Engine::update()
{
	mainPlayer->update();

	playerRect.x = mainPlayer->getPosX();
	playerRect.y = mainPlayer->getPosY();
}

void Engine::render()
{
	//clear everything
	
	

	SDL_RenderClear(renderer);

	
	SDL_SetRenderDrawColor(renderer, 255, 2555, 255, 255);
	SDL_RenderCopy(renderer, playerTexture, NULL, &playerRect);//player render

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


SDL_Texture* Engine::textureLoader(string filename) {
	SDL_Surface* tempSurface = IMG_Load(filename.c_str());

	SDL_Texture *resultText = SDL_CreateTextureFromSurface(renderer, tempSurface);


	SDL_FreeSurface(tempSurface);
	tempSurface = nullptr;
	return resultText;
}