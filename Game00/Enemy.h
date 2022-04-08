#pragma once
#include "MovingEntity.h"
class Enemy :public MovingEntity
{
public:
	Enemy(int x, int y, SDL_Texture* texture) :MovingEntity(x, y, 32, 32, 30) { enemyTexture = texture; };
	~Enemy() {  };

	void update() ;

	void setDead() { dead = true; };

	bool isDead(){ return dead; };

	void render(SDL_Renderer * renderer,Camera* camera);

private:
	
	bool dead = false;
	SDL_Rect displayRect;
	SDL_Texture * enemyTexture;
};

