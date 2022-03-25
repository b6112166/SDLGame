#include "Map.h"

Map::Map(int mapNumber,SDL_Texture * tileSet) 
	:tileSet(tileSet)
{

	
	//set tile set
	
	//render tiles
	tiles = new int* [25];
	for (int i = 0; i < 25; i++) 
	{
		tiles[i] = new int[25];
	}
	string filename = "assets/maps/map" + to_string(mapNumber) + ".txt";
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
	

	
	//init
	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 25; j++) {
			tiles[i][j] = 0;
		}
	}

	//todo: add loading from file
	ifstream file;
	string line;
	file.open(f);

	int i = 0;
	while (getline(file, line)) {
		for (int j = 0; j < 25; j++) {
			
			

			//parses each number using the delimiter ","
			int delimiterPos = line.find(",");
			string numberStr = line.substr(0, delimiterPos);

			tiles[i][j] = atoi(numberStr.c_str());
			cout << "loaded " << tiles[i][j]<<endl;
			line.erase(0, delimiterPos + 1); //also removes the delimiter
		}
		i++;
	}

	cout << endl << "memory inside the map after loading"<<endl;

	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 25; j++) {
			cout << tiles[i][j] << ",";
		}
		cout << endl;
	}



	
}

int Map::getTile(int row, int col) {
	return tiles[row][col];
}

void Map::render(SDL_Renderer * renderer) {
	//todo render the map
	
	//test render
	SDL_RenderCopy(renderer, tileSet, NULL, NULL);

}