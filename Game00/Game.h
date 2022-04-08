#pragma once
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <iostream>
#include "Player.h"
#include "direction.h"
#include "string.h"
#include "Map.h"
#include <vector>
#include "Camera.h"
#include "Enemy.h"
#include "Sword.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_mixer.h"

using namespace std;
/*
struct Camera {
	int x;
	int y;
	int w;
	int h;
};

*/
class Game
{
	//handle user input
	//update objects
	//renders 
public:
	Game();
	~Game();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	void handleEvents();
	void update();
	void render();
	void clean();
	void checkCollision();

	bool overlap(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2);


	bool running();

protected:



private:
	class Player* mainPlayer;
	bool isRunning;
	SDL_Window* gameWindow;
	SDL_Renderer* renderer;

	Mix_Music * bgm;
	Mix_Chunk* slashSound;
	Sword * playerSword;

	Map* map;
	TTF_Font* font;
	int score;

	SDL_Texture* loadTexture(string filename);
	Camera * mainCamera;
	//entity list
	vector<Enemy * > enemyList; //does not include the player
	SDL_Texture* enemyTexture;
};

