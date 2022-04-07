#include "Map.h"

Map::Map(int mapNumber,SDL_Texture * tileSet) 
	:tileSet(tileSet)
{

	
	
	
	
	
	string f = "assets/maps/dungeonmap1.txt";
	cout << "loading" << f<<endl; 
	//load render tiles

	tiles = LoadTiles(f.c_str(), 100, 100);
	

	//load collision tiles
	f = "assets/maps/dungeonmap1collision.txt";
	collisionTiles = LoadTiles(f.c_str(), 100, 100);

	//load  spawn points
	f = "assets/maps/dungeonmap1spawns.txt";
	spawnPointTiles = LoadTiles(f.c_str(), 100, 100);

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			cout << collisionTiles[i][j]<<',';
		}
		cout << endl;
	}
}

Map::~Map() {
	for (int i = 0; i < 100; i++) 
	{
		delete[] tiles[i];
	}

	delete[] tiles;
	for (int i = 0; i < 100; i++)
	{
		delete[] collisionTiles[i];
	}

	delete[] collisionTiles;

	for (int i = 0; i < 100; i++)
	{
		delete[] spawnPointTiles[i];
	}
	delete[] spawnPointTiles;

}

int** Map::LoadTiles(const char* f,const int row,const int col) {
	
	//returns a 2d int array used for tiles 
	
	int** result = new int* [row];

	for (int i = 0; i < col; i++)
	{
		result[i] = new int[col];
	}
	
	//init
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++) {
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
		for (int j = 0; j < col; j++) {
			
			

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






void Map::render(SDL_Renderer * renderer,Camera * camera) {
	//todo render the map
	

	
	SDL_Rect srcRect;//rect from tileset, to select tiles from
	SDL_Rect destRect;//rect to render onto the screen, tile position on map.

	srcRect.w = TILEW;
	srcRect.h = TILEH;
	destRect.w = scaledW;
	destRect.h = scaledH;
	int cameraX = camera->getX();//reusability
	int cameraY = camera->getY();

	
	//i = y cord
	//j = x cord
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			
			//find x,y on the tileset based on width and height
			if (tiles[i][j] != 0) {
				int tileID = tiles[i][j]; //id starts at 1
				
				

				int targetX = scaledW * j; //recalculated x coord after scaling 
				int targetY = scaledH * i;//recalculated y coord after scaling
				if (targetX + scaledW > cameraX && targetY + scaledH > cameraY) {//only render if the tile is inside the screen

					destRect.x = (targetX - cameraX);
					destRect.y = (targetY - cameraY); 
					

					srcRect.x = TILEW * ((tileID - 1) % 24);		// to calculate x , x = tile width * (id-1 % size per row for tileset (32) )  
					srcRect.y = TILEH * ((tileID - 1) / 24);		//to calculate y, y = tile height * floor (id-1/ size per row tileset (32) )
					
					SDL_RenderCopy(renderer, tileSet, &srcRect, &destRect);
				}
				

			}
			
		}
	}




}