#pragma once



#include "MovingEntity.h"
class Player : public MovingEntity
{
public:
	Player();

	int getHp();
	
	void shoot();
	
	void itemAquire(int);
	void damagedBy(int);
	void destroy();
	void walk(direction);
	void update();

	void stop();

	void jump();
	
	
	direction getCurrentDirection() { return faceDirection; };

	~Player() {};


private:
	bool jumpEnabled;
	int HP = 100;
	int movement_speed = 10;
	int bomb_count =3;
	int blast_radius =50;
	int attack_damage = 10;
	

	
	
};

