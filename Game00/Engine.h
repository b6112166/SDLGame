#pragma once
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <iostream>
#include "Player.h"

extern enum direction;

using namespace std;

class Engine
{
	//handle user input
	//update objects
	//renders 
public:
	Engine();
	~Engine();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	void handleEvents();
	void update();
	void render();
	void clean();

	bool running();

private:
	bool isRunning;
	SDL_Window* gameWindow;
	SDL_Renderer* renderer;
	Entity* enemyEntityList;
	Player* mainPlayer;
	SDL_Rect* enemyRectList;
	SDL_Texture* playerTexture;
	SDL_Rect* playerRect;

};

