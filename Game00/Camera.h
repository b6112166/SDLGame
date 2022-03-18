#pragma once

class Camera {


public:
	Camera(int x, int y, int w, int h) {
		this->w = w;
		this->h = h;
		this->x = x;
		this->y = y;

	}
	~Camera() {};

	int getW() {return w};

	int getH() {return h};

	int getX() {return x};

	int getY() {return y};

protected:
	int x;
	int y;
	int w;
	int h;
};

