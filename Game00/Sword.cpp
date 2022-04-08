#include "Sword.h"

void Sword::update() {
	if (owner->getAttackDirection() == direction::d_down) {
		x = owner->getPosX() + 17;
		y = owner->getPosY() + 48;

	}
	else if (owner->getAttackDirection() == direction::d_up) {
		x = owner->getPosX() + 17;
		y = owner->getPosY() - 37;
	}

}



void Sword::render(SDL_Renderer* renderer, Camera* camera)
{

	swordRect.x = (x - camera->getX());
	swordRect.y = (y - camera->getY());
	swordRect.w = width;
	swordRect.h = height;

	SDL_RendererFlip flip = SDL_FLIP_NONE;
	if (owner->getAttackDirection() == direction::d_down) {
		flip = SDL_FLIP_VERTICAL;
	}
	


	SDL_RenderCopyEx(renderer, swordTexture, NULL, &swordRect,0,NULL,flip);//sword render


}