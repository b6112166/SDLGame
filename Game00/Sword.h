#pragma once
#include "Entity.h"
#include "Direction.h"
class Sword :
    public Entity
{
public:
    Sword(Entity * owner) :Entity(owner->getPosX(), owner->getPosY(), 13, 37) {};
    void update();


private:
    



};

