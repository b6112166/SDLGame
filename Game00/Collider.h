#pragma once
#include "Entity.h"

class Collider {
public:

	Collider(Entity* owner) :
		owner(owner),
		w(owner->getWidth()),
		h(owner->getHeight())
	{}
	~Collider() {}




private:

	int w;
	int h;
	Entity* owner;
};