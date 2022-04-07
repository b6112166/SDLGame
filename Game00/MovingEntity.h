
#pragma once
#include "Entity.h"


class MovingEntity : public Entity {
public:
	MovingEntity(int x,int y,int w, int h,int ms):Entity(x,y,w,h) {
		movementSpeed = ms;
		isMoving = false;
		faceDirection = direction::d_right;
		

	};
	~MovingEntity() {};
	




protected:


	
	void move() {
		if (isMoving)
		{
	
			//direction check
			switch (faceDirection) {
				//move left
			case direction::d_left:
				x -= movementSpeed;
				break;
				//move right
			case direction::d_right:
				x += movementSpeed;
				break;
			case direction::d_down:
				y += movementSpeed;
				break;
			case direction::d_up:
				y -= movementSpeed;
			}

		}
	};
	

	int movementSpeed;
	bool isMoving;
	direction faceDirection;
	

};