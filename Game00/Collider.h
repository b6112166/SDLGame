#pragma once
#include "Game.h"

class Collider {
public:

	Collider(Entity* owner):
	x(owner->getPosX()),
	y(owner->getPosY()),
	w(owner->getWidth()),
	h(owner->getHeight())
	{}
	~Collider() {}


private:
	int x;
	int y;
	int w;
	int h;
	Entity * owner;
};