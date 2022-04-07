#pragma once
#include "MovingEntity.h"

class Player : public MovingEntity{
public:
	Player(int x, int y, SDL_Texture* playerTexture) :
		MovingEntity(x, y, 48, 48, 16),
		playerTexture(playerTexture) {
		playerRect = { x,y,width,height };
		dead = false;
		lastX = x;
		lastY = y;


	};
	~Player() { SDL_DestroyTexture(playerTexture); };

	
	
	void itemAquire(int);

	void update() ;
	void handleControl(const Uint8 * state);



	bool isDead() { return dead; };
	
	void handleCollision(int);

	void render(SDL_Renderer* renderer,class Camera * camera); 
	




private:

	int movement_speed = 10;


	int lastX;
	int lastY;
	bool dead;

	SDL_Rect playerRect;

	SDL_Texture* playerTexture;
	
};

