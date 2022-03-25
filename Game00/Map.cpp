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
	


	SDL_Rect srcRect;//rect from tileset, to select tiles from
	SDL_Rect destRect;//rect to render onto the screen, tile position on map.
	srcRect.w = TILEW;
	srcRect.h = TILEH;
	destRect.w = TILEH;
	destRect.h = TILEH;
	//i = y cord
	//j = x cord
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 25; j++) {
			
			//find x,y on the tileset based on width and height
			if (tiles[i][j] != 0) {
				int tileID = tiles[i][j]; //id starts at 1

				destRect.x = TILEW * j;
				destRect.y = TILEH * i;


				srcRect.x = TILEW * ((tileID - 1) % 32);		// to calculate x , x = tile width * (id-1 % size per row for tileset (32) )  
				srcRect.y = TILEH * ((tileID - 1) / 32);		//to calculate y, y = tile height * floor (id-1/ size per row tileset (32) )

			}
			SDL_RenderCopy(renderer, tileSet,&srcRect,&destRect);
		}
	}

	//test render
	/*
		SDL_RenderCopy(renderer, tileSet, NULL, NULL);
	*/


}