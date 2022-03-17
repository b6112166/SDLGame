
#pragma once
#include "Entity.h"


class MovingEntity : public Entity {
public:
	MovingEntity(int x,int y,int type,int ms):Entity(x,y,type) {
		movementSpeed = ms;
		isMoving = false;
		faceDirection = direction::d_right;
		gravity = 1;
		xVelocity = 0;
		yVelocity = 0;

	};
	~MovingEntity() {};




protected:

	int gravity;
	virtual void update() {};

	int movementSpeed;
	bool isMoving;
	direction faceDirection;
	
	int xVelocity;
	int yVelocity;
};