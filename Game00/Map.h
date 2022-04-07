
#pragma once
#include<fstream>
#include<iostream>
#include<string>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "Camera.h"

using namespace std;
class Map {
public:
	Map(int mapNumber,SDL_Texture* tileSet);
	~Map();
	
	

	void render(SDL_Renderer* renderer,class Camera * camera);
	int getCollisionTile(int row, int col) { return collisionTiles[col][row]; };

	int getSpwanTile(int row, int col) { return spawnPointTiles[col][row]; };
	
	int getScaledTileW() { return scaledW; };
	int getScaledTileH() { return scaledH; };
	
	int getTileX(int col ) { return scaledW * col; };
	int getTileY(int row) { return scaledH * row;  };

protected:
	int** tiles;

	int** collisionTiles;

	int** spawnPointTiles;

	int** LoadTiles(const char*,int,int);



	SDL_Texture* tileSet;

	int scale = 3;

	const int TILEW = 16;
	const int TILEH = 16;

	const int scaledW = TILEW * scale;

	const int scaledH = TILEH * scale;
};