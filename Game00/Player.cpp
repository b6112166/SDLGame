#include "Player.h"



Player::Player():Entity(){
	type = 1;
	x = 100; 
	y = 100;

	faceDirection = d_right;



}

void Player::move(direction d) 
{
	switch (d) {
	case d_left:
		x -= movement_speed;
		break;
	
	case d_right:
		x += movement_speed;
		break;
	
	case d_up:
		y -= movement_speed;
		break;

	case d_down:
		y += movement_speed;
		break;
	
	case d_upleft:
		y -= movement_speed;
		x -= movement_speed;
		break;

	case d_upright:
		y -= movement_speed;
		x += movement_speed;
		break;
	case d_downleft:
		y += movement_speed;
		x -= movement_speed;
		break;
	case d_downright:
		y += movement_speed;
		x += movement_speed;
		break;
	}

}
