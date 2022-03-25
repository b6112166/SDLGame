#pragma once
#include "MovingEntity.h"

class Player : public MovingEntity
{
public:
	Player(int x, int y, SDL_Texture* playerTexture);

	int getHp() { return HP; };
	
	void shoot();
	
	void itemAquire(int);
	void damagedBy(int);
	void destroy();
	void walk(direction);
	void update() override;

	void stop();

	void jump();
	
	void render(SDL_Renderer* renderer); 
	
	direction getCurrentDirection() { return faceDirection; };

	~Player() {};


private:
	bool jumpEnabled;
	int HP = 100;
	int movement_speed = 10;
	int bomb_count =3;
	int blast_radius =50;
	int attack_damage = 10;
	
	SDL_Rect playerRect;

	SDL_Texture* playerTexture;
	
};

