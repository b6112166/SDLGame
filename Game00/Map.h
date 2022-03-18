
#pragma once
#include<fstream>
#include<iostream>
#include<string>
using namespace std;
class Map {
public:
	Map(int mapNumber);
	~Map();
	const int TILEW = 24;
	const int TILEH = 24;

	int getTile(int row, int col);
	
protected:
	int** tiles;

	int** collisionTiles;


	void LoadMap(const char* filename);
};