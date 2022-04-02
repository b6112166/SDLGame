
#pragma once
#include<fstream>
#include<iostream>
#include<string>
#include"Game.h"

using namespace std;
class Map {
public:
	Map(int mapNumber,SDL_Texture* tileSet);
	~Map();
	
	

	void render(SDL_Renderer* renderer,class Camera * camera);
	int getCollisionTile(int row, int col);

	int getScaledTileW() { return scaledW; };
	int getScaledTileH() { return scaledH; };
	
	int getTileX(int col ) { return scaledW * col; };
	int getTileY(int row) { return scaledH * row;  };

protected:
	int** tiles;

	int** collisionTiles;


	int** LoadTiles(const char*,int,int);


	SDL_Texture* tileSet;

	

	const int TILEW = 16;
	const int TILEH = 16;

	const int scaledW = TILEW * 4;

	const int scaledH = TILEH * 4;
};