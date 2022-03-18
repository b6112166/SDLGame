
#pragma once
#include<fstream>
#include<iostream>
#include<string>
using namespace std;
class Map {
public:
	Map(int mapNumber);
	~Map();


protected:
	int** tiles;

	void LoadMap(const char* filename);
};