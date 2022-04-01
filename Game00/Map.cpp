#include "Map.h"

Map::Map(int mapNumber,SDL_Texture * tileSet) 
	:tileSet(tileSet)
{

	
	
	
	
	
	string f = "assets/maps/map1.txt";
	cout << "loading" << f<<endl; 
	//load render tiles

	tiles = LoadTiles(f.c_str(), 25, 25);
	

	//load collision tiles
	f = "assets/maps/testmapcol.txt";
	collisionTiles = LoadTiles(f.c_str(), 25, 25);
}

Map::~Map() {
	for (int i = 0; i < 25; i++) 
	{
		delete[] tiles[i];
	}

	delete[] tiles;
	for (int i = 0; i < 25; i++)
	{
		delete[] collisionTiles[i];
	}

	delete[] collisionTiles;
}

int** Map::LoadTiles(const char* f,int col,int row) {
	
	//returns a 2d int array used for tiles
	
	int** result = new int* [25];

	for (int i = 0; i < 25; i++)
	{
		result[i] = new int[25];
	}
	
	//init
	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 25; j++) {
			result[i][j] = 0;
		}
	}

	//loading from file
	ifstream file;
	string line;
	file.open(f);
	if (!file) {
		cout << "file reading failed for "<<f<<endl;
	}

	int i = 0;
	while (getline(file, line)) {
		for (int j = 0; j < 25; j++) {
			
			

			//parses each number using the delimiter ","
			int delimiterPos = line.find(",");
			string numberStr = line.substr(0, delimiterPos);
			
			result[i][j] = atoi(numberStr.c_str());
		
			line.erase(0, delimiterPos + 1); //also removes the delimiter
		}
		i++;
	}

	

	return result;



	
}




int Map::getTile(int row, int col) {
	return tiles[row][col];
}

void Map::render(SDL_Renderer * renderer,Camera * camera) {
	//todo render the map
	

	
	SDL_Rect srcRect;//rect from tileset, to select tiles from
	SDL_Rect destRect;//rect to render onto the screen, tile position on map.
	int scale = 4 ;
	srcRect.w = TILEW;
	srcRect.h = TILEH;
	destRect.w = TILEH * scale;
	destRect.h = TILEH * scale;
	int cameraX = camera->getX();//reusability
	int cameraY = camera->getY();

	int onScreenW = TILEW * scale;//actual width on screen
	int onScreenH = TILEH * scale;//actual height on screen
	//i = y cord
	//j = x cord
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 25; j++) {
			
			//find x,y on the tileset based on width and height
			if (tiles[i][j] != 0) {
				int tileID = tiles[i][j]; //id starts at 1
				
				

				int targetX = onScreenW* j; //recalculated x coord after scaling 
				int targetY = onScreenH * i;//recalculated y coord after scaling
				if (targetX + onScreenW > cameraX && targetY + onScreenH > cameraY) {//only render if the tile is inside the screen

					destRect.x = (targetX - cameraX);
					destRect.y = (targetY - cameraY); 
					

					srcRect.x = TILEW * ((tileID - 1) % 32);		// to calculate x , x = tile width * (id-1 % size per row for tileset (32) )  
					srcRect.y = TILEH * ((tileID - 1) / 32);		//to calculate y, y = tile height * floor (id-1/ size per row tileset (32) )
					
					SDL_RenderCopy(renderer, tileSet, &srcRect, &destRect);
				}
				

			}
			
		}
	}




}