#pragma once

#include "direction.h"
//interface class
class Entity
{

public:
	Entity(int x_input, int y_input, int type_input) {
		x = x_input; 
		y = y_input; 
		type = type_input; 
		
	};

	~Entity() {};

	int getPosX() { return x; };
	int getPosY() { return y; };
	virtual void update() {};


protected:
	int type;
	//bool visible;
	int x ;
	int y ;
	
	

private:
};

