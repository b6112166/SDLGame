#include "Enemy.h"

void Enemy::update() {

}


void Enemy::render(SDL_Renderer * renderer,Camera* camera) {
	displayRect.x = (x - camera->getX());
	displayRect.y = (y - camera->getY());
	displayRect.w = width;
	displayRect.h = height;

	SDL_RenderCopy(renderer, enemyTexture, NULL, &displayRect);//player render
}