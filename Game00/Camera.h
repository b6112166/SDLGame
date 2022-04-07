#pragma once
#include "Entity.h"

using namespace std;
class Camera {
private:
	int x;
	int y;
	int w;
	int h;
	
	class Entity * target;//target that the camera should focus on
public:
	Camera(Entity * target,int windowWidth,int windowHeight);
	~Camera() {};

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



};