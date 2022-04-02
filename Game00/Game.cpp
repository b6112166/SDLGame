#include "Game.h"

using namespace std;



Game::Game() 
{
	isRunning = false;
}

Game::~Game() 
{
	clean();
}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) 
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
			

		

			
			
			
			
			

			mainPlayer = new Player(100,100,loadTexture("assets/ball.png"));//need to provide texture
			
			//Camera mainCamera = { mainPlayer->getPosX() - width / 2 , mainPlayer->getPosY() - width / 2, width,height};
			mainCamera = new Camera(mainPlayer,width,height);
			
			map = new Map(1, loadTexture("assets/tileset/Wasteland-Files.png"));
			
		}
	}
}

bool Game::running() {
	return isRunning;
}

void Game::handleEvents()
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
	
	//player control
	mainPlayer->handleControl(state);
}

void Game::update()
{


	mainPlayer->update();
	checkCollision();
	mainCamera->update();
	
}

void Game::render()
{
	//clear everything
	
	//load main camera attribute
	
	SDL_RenderClear(renderer);

	
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	//map render
	map->render(renderer,mainCamera);

	//player render
	mainPlayer->render(renderer,mainCamera);

	
	//draw
	SDL_RenderPresent(renderer);

}

void Game::clean()
{
	SDL_DestroyWindow(gameWindow);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	cout << "Game exited,cya!"<<endl;
}




SDL_Texture* Game::loadTexture(string filename) {
	SDL_Surface* tempSurface = IMG_Load(filename.c_str());

	SDL_Texture* resultText = SDL_CreateTextureFromSurface(renderer, tempSurface);


	SDL_FreeSurface(tempSurface);
	tempSurface = nullptr;
	return resultText;
}

void Game::checkCollision()
{
	int playerX = mainPlayer->getPosX();
	int playerY = mainPlayer->getPosY();
	int playerW = mainPlayer->getWidth();
	int playerH = mainPlayer->getHeight();


	int tileH = map->getScaledTileH();
	int tileW = map->getScaledTileW();

	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 25; j++) {
			if (map->getCollisionTile(i,j) == 1) {//check for collision if tile has collision enabled
				if (overlap(playerX, playerY, playerW, playerH, map->getTileX(j), map->getTileY(i), tileW, tileH)) {
					mainPlayer->handleCollision();
				}
			}
		}
	}
}


bool Game::overlap(int x1,int y1,int w1,int h1, int x2,int y2,int w2,int h2) {
	if (x1 + w1 >= x2 && //left check
		x2 + w2 >= x1 && //right check
		y1 + h1 >= y2 && //up check
		y2 + h2 >= y1 //down check
		) {

		return true;
	}

	return false;
}