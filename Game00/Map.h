
#pragma once
#include<fstream>
#include<iostream>
#include<string>
#include"Engine.h"

using namespace std;
class Map {
public:
	Map(int mapNumber,SDL_Texture* tileSet);
	~Map();
	
	void render(SDL_Renderer* renderer);
	int getTile(int row, int col);
	
protected:
	int** tiles;

	int** collisionTiles;


	void LoadMap(const char* filename);

	SDL_Texture* tileSet;

	const int TILEW = 24;
	const int TILEH = 24;
};