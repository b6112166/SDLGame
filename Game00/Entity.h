#pragma once

#include "direction.h"
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "Camera.h"
#include <iostream>
using namespace std;
//interface class
class Entity
{

public:
	Entity(int x, int y,int w,int h):
	x(x),
	y(y),
	width(w),
	height(h)
	
	{
		
		
	};

	~Entity() {};

	int getPosX() { return x; };
	int getPosY() { return y; };
	int getWidth() { return width; };
	int getHeight() { return height; };
	
	
protected:
	
	//bool visible;
	int x ;
	int y ;
	int width;
	int height;
	

private:
};

