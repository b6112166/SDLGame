
#pragma once
#include<fstream>
#include<iostream>
#include<string>
class Map {
public:
	Map(int mapNumber);
	~Map();


protected:
	int** tiles;

	int** LoadMap(const char* filename);
};