#pragma once
#include "Player.h"
#include "Direction.h"
class Sword :
    public Entity
{
public:
    Sword(Player* owner, SDL_Texture* texture) :Entity(owner->getPosX(), owner->getPosY(), 13, 37) { swordTexture = texture; };
    void update();


private:
    
    SDL_Texture * swordTexture ;


};

