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
				
				IMG_Init(IMG_INIT_PNG);

				//font init
				TTF_Init();

				font = TTF_OpenFont("assets/MochiyPopPOne-Regular.ttf",24);
				
				//bgm init

				if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
					cout << "Mixer error:" << Mix_GetError()<<endl;
				}
			

				bgm = Mix_LoadMUS("assets/02-Overworld.wav");
				
				Mix_PlayMusic(bgm, -1);

				slashSound = Mix_LoadWAV("assets/slash.wav");

				enemyTexture = loadTexture("assets/enemy.png");

				mainPlayer = new Player(100, 100, loadTexture("assets/mainCharacter.png"));//player init
				playerSword = new Sword(mainPlayer, loadTexture("assets/sword.png"));//sword init
				
				mainCamera = new Camera(mainPlayer, width, height);

				map = new Map(1, loadTexture("assets/tileset/Dungeon_tileset.png"));

				//spawn enemy from spawn point

				for (int i = 0; i < 100; i++) {
					for (int j = 0; j < 100; j++) {

						//check if enemy spawn
						if (map->getSpwanTile(i, j) == 1) {
							Enemy* Temp = new Enemy(map->getTileX(i), map->getTileY(j), enemyTexture);
							enemyList.push_back(Temp);

						}

					}
				}

				score = 0;
				isRunning = true;

			}

			

			


			

			
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
	playerSword->update();


	for (Enemy * e : enemyList) {
		e->update();
	}
	
	
	
	



	checkCollision();
	int i = 0;
	while (i < enemyList.size()  && !(enemyList[i]->isDead()) ) {
		i++;
	}

	if (i < enemyList.size()) { // i == enemyList.size() if no dead enemy were found
		enemyList.erase(enemyList.begin() + i);
	}
	//end the game if all enemies are dead
	if (enemyList.size() == 0) {
		isRunning = false;
	}

	//remove dead enemy
	
	mainCamera->update();
	
	//check if player is dead, if true close the game
	if (mainPlayer->isDead()) {
		isRunning = false;
	}


}

void Game::render()
{
	//clear everything
	
	//load main camera attribute
	
	SDL_RenderClear(renderer);

	

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	//map render
	map->render(renderer,mainCamera);

	//render enemy

	for (Enemy * e : enemyList) {
		e->render(renderer,mainCamera);
	}

	//player render
	mainPlayer->render(renderer,mainCamera);
	//sword render
	playerSword->render(renderer,mainCamera);

	//render text
	string scoreText = "Score:" + to_string(score);
	SDL_Color textColor = { 255,255,255,255 };
	SDL_Surface* tempSurface = TTF_RenderText_Solid(font, scoreText.c_str(), textColor);
	SDL_Rect textTarget = { 800,100, tempSurface->w,tempSurface->h };
	SDL_Texture* tempTexture = SDL_CreateTextureFromSurface(renderer, tempSurface);

	SDL_RenderCopy(renderer,tempTexture,NULL,&textTarget);


	SDL_DestroyTexture(tempTexture);
	tempTexture = nullptr;
	SDL_FreeSurface(tempSurface);
	tempSurface = nullptr;


	//draw
	SDL_RenderPresent(renderer);

}

void Game::clean()
{


	Mix_FreeMusic(bgm);
	TTF_CloseFont(font);
	font = nullptr;
	delete map;
	delete mainPlayer;
	delete playerSword;
	enemyList.clear();
	SDL_DestroyTexture(enemyTexture);
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

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (map->getCollisionTile(i,j) == 1) {//check for collision if tile has collision enabled
				if (overlap(playerX, playerY, playerW, playerH, map->getTileX(i), map->getTileY(j), tileW, tileH)) {
					mainPlayer->handleCollision(1);
				}
			}
		}
	}

	for (Enemy * e : enemyList) {
		if (overlap(playerX, playerY, playerW, playerH, e->getPosX(), e->getPosY(), e->getWidth(), e->getHeight())) {
			mainPlayer->handleCollision(2);
		}
		else if (overlap(e->getPosX(), e->getPosY(), e->getWidth(), e->getHeight(), playerSword->getPosX(), playerSword->getPosY(), playerSword->getWidth(), playerSword->getHeight())) {
			e->setDead();
			score++;
			Mix_PlayChannel(-1, slashSound, 0);
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