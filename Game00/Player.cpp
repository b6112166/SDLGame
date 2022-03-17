#include "Player.h"



Player::Player():MovingEntity(100,100,1,3){
	
	jumpEnabled = false;


}


void Player::walk(direction d) 
{	
	faceDirection = d;
	isMoving = true;
}

void Player::stop() 
{
	isMoving = false;
}

void Player::jump() 
{
	if (jumpEnabled) //temp code, to be replaced with proper collision code
	{
		yVelocity = -10;
		jumpEnabled = false;
	}
}


void Player::update()
{
	//movement update
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
		}

	}

	//gravity update
	 //temp code, to be replaced with proper collision code
	y += yVelocity;
	if (y <= 400) {
		yVelocity += gravity;
		
	}
	else {
		yVelocity = 0;//stop
		jumpEnabled = true;//jump reset
	}
	
}
