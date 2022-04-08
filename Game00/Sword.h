#pragma once
#include "Player.h"
#include "Direction.h"
class Sword :
    public Entity
{
public:
    Sword(Player* owner, SDL_Texture* texture) :Entity(owner->getPosX(), owner->getPosY(), 13, 74),owner(owner) { swordTexture = texture; };
    void update();
    void render(SDL_Renderer* renderer, class Camera* camera);
    ~Sword() { SDL_DestroyTexture(swordTexture); }

private:
    
    SDL_Texture * swordTexture ;
    Player* owner;
    SDL_Rect swordRect;
};

