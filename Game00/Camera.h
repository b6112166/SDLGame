#pragma once
#include "Game.h"
using namespace std;
class Camera {
private:
	int x;
	int y;
	int w;
	int h;
	int scale;//how much to scale all the entities by
	class Entity * target;
public:
	Camera(Entity * target,int scale,int windowWidth,int windowHeight);


	void update();//keeps the target centered when given x and y
	
	int getX() {
		return x;
	}

	int getY() {
		return y;
	}

	int getW() {
		return w;
	}

	int getH() {
		return h;
	}
	int getScale() {
		return scale;
	}


};