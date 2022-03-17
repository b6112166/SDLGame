#pragma once
#include "Entity.h"


class StaticEntity : public Entity {


public:
	StaticEntity(int x,int y,int type):Entity(x,y,type) {};
	~StaticEntity() {};




};