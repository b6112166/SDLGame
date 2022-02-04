#pragma once

//charater art from https://opengameart.org/users/buch

#include "Entity.h"
class Player : public Entity
{
public:
	Player();

	int getHp();
	
	void attack();
	
	void itemAquire(int);
	void damagedBy(int);
	void destroy();
	void move(direction);


	
	bool getCurrentDirection() { return faceDirection; };

	~Player() {};


private:
	int HP = 100;
	int movement_speed = 10;
	int bomb_count =3;
	int blast_radius =50;
	int attack_damage = 10;
	

	direction faceDirection;
	
};

