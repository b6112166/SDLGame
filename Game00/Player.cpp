#pragma once
#include "Player.h"








void Player::update() 
{

	lastX = x;
	lastY = y;
	//movement update
	move();



	//gravity update
	 //temp code, to be replaced with proper collision code
	
	//check collision


	

}

void Player::render(SDL_Renderer* renderer, Camera* camera)
{

	playerRect.x = (x - camera->getX()) ;
	playerRect.y = (y - camera->getY()) ;
	playerRect.w = width ;
	playerRect.h = height ;
	
	SDL_RenderCopy(renderer, playerTexture, NULL, &playerRect);//player render

	
}

void Player::handleControl(const Uint8* state) {
	if (!state[SDL_SCANCODE_A] && !state[SDL_SCANCODE_D] && !state[SDL_SCANCODE_W] && !state[SDL_SCANCODE_S]) //if none of the buttons are held 
	{
		
		isMoving = false;
		
	}
	else
	{
		if (state[SDL_SCANCODE_A])
		{
			faceDirection = direction::d_left;
			isMoving = true;
		}
		//left 
		else if (state[SDL_SCANCODE_D])
		{

			faceDirection = direction::d_right;
			isMoving = true;
		}
		else if(state[SDL_SCANCODE_W])
		{
			faceDirection = direction::d_up;
			isMoving = true;

		}
		else if(state[SDL_SCANCODE_S]) {
			faceDirection = direction::d_down;
			isMoving = true;

		}
		//right


	}
	if (state[SDL_SCANCODE_SPACE])
	{
	
	}
}


void Player::handleCollision(int condition) {
	//condition 1, player has hit the wall, condition 2, player has hit the enemy
	if (condition == 1) {
		if (faceDirection == direction::d_down || faceDirection == direction::d_up) { // if moving vertical
			y = lastY; //revert y
		}
		else if (faceDirection == direction::d_left || faceDirection == direction::d_right) {// if moving horizontal
			x = lastX;//revert last x
		}
	}
	else if (condition == 2) {
		dead = true;
	}
}