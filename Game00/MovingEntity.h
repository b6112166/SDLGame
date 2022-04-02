
#pragma once
#include "Entity.h"


class MovingEntity : public Entity {
public:
	MovingEntity(int x,int y,int w, int h,int type,int ms):Entity(x,y,w,h,type) {
		movementSpeed = ms;
		isMoving = false;
		faceDirection = direction::d_right;
		

	};
	~MovingEntity() {};




protected:


	virtual void update() {};

	int movementSpeed;
	bool isMoving;
	direction faceDirection;
	

};