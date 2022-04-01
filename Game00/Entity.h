#pragma once

#include "direction.h"
#include "Game.h"
//interface class
class Entity
{

public:
	Entity(int x, int y,int w,int h,int type):
	x(x),
	y(y),
	width(w),
	height(h),
	type(type)
	{
		
		
	};

	~Entity() {};

	int getPosX() { return x; };
	int getPosY() { return y; };
	int getWidth() { return width; };
	int getHeight() { return height; };
	virtual void update() {};

	
protected:
	int type;
	//bool visible;
	int x ;
	int y ;
	int width;
	int height;
	

private:
};

