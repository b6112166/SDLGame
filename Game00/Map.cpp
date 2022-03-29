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

void Map::render(SDL_Renderer * renderer,Camera * camera) {
	//todo render the map
	


	SDL_Rect srcRect;//rect from tileset, to select tiles from
	SDL_Rect destRect;//rect to render onto the screen, tile position on map.
	int scale = camera->getScale();
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