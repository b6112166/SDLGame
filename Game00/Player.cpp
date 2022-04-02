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

	lastX = x;
	lastY = y;
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
			case direction::d_down:
				y += movementSpeed;
				break;
			case direction::d_up:
				y -= movementSpeed;
		}

	}
	//check collision

	cout << "y:" << y << endl;

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


void Player::handleCollision() {
	
		
		if (faceDirection == direction::d_down || faceDirection == direction::d_up) { // if moving vertical
			y = lastY; //revert y
		}
		else if (faceDirection == direction::d_left || faceDirection == direction::d_right) {// if moving horizontal
			x = lastX;//revert last x
		}
	
}