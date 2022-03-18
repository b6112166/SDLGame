#include "Map.h"

Map::Map(int mapNumber) {

	//render tiles
	tiles = new int* [25];
	for (int i = 0; i < 25; i++) 
	{
		tiles[i] = new int[25];
	}
	string filename = "map" + to_string(mapNumber) + ".xml";
	LoadMap(filename.c_str());

}

Map::~Map() {
	for (int i = 0; i < 25; i++) 
	{
		delete[] tiles[i];
	}

	delete[] tiles;
}

void Map::LoadMap(const char* f) {
	//todo: add loading from file

	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 25; j++) {
			tiles[i][j] = 0;
		}
	}

	
}

int Map::getTile(int row, int col) {
	return tiles[row][col];
}