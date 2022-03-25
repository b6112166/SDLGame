#pragma once
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <iostream>
#include "Player.h"
#include "direction.h"
#include "string.h"
#include "Map.h"
using namespace std;
/*
struct Camera {
	int x;
	int y;
	int w;
	int h;
};

*/
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
	void handleCollision();

	bool running();

protected:

	class Player* mainPlayer;
	bool isRunning;
	SDL_Window* gameWindow;
	SDL_Renderer* renderer;
	

	class Map * map;

private:

	SDL_Texture* loadTexture(string filename);
};

