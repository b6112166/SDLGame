#include "Player.h"



Player::Player() {
	type = 1;
	x = 100; 
	y = 100;

	faceDirection = d_right;



}

void Player::moveHorizontal(bool right) 
{
	if (right) {
		x += movement_speed;
		
	}

	else {
		x -= movement_speed;
	
	}
	
}

void Player::moveVertical(bool up) 
{
	if (up) {
		y += movement_speed;
	}
	else {
		y -= movement_speed;
	}
	
}

