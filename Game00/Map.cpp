#include "Map.h"

Map::Map(int mapNumber) {
	tiles = new int* [25];
	for (int i = 0; i < 25; i++) {
		tiles[i] = new int[25];
	}
	std::string filename = "map" + std::to_string(mapNumber) + ".xml";
	LoadMap(filename.c_str());
}