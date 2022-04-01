#include "Player.h"



Player::Player(int x,int y,SDL_Texture * texture)
	:MovingEntity(x,y,64,64,1,16),
	playerTexture(texture)
{
	playerRect = { x,y,width,height };
	jumpEnabled = false;


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
					x -= movementSpeed ;
					break;
				//move right
			case direction::d_right:
					x += movementSpeed ;
					break;
		}

	}
	//check collision


	//gravity update
	 //temp code, to be replaced with proper collision code
	y += yVelocity;
	if (y <= 700) {
		yVelocity += gravity;
		
	}
	else {
		yVelocity = 0;//stop
		jumpEnabled = true;//jump reset
	}
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
	if ((!state[SDL_SCANCODE_A] && !state[SDL_SCANCODE_D]) || (state[SDL_SCANCODE_A] && state[SDL_SCANCODE_D]))//not moving
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
		//right


	}
	if (state[SDL_SCANCODE_SPACE])
	{
		//jump
		if (jumpEnabled) //temp code, to be replaced with proper collision code
		{
			yVelocity = -50 ;
			jumpEnabled = false;
		}
	}
}