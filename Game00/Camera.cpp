#include "Camera.h"

Camera::Camera(Entity * target, int windowWidth, int windowHeight):
target(target)
{
	w = windowWidth ;
	h = windowHeight;
	//keep x and y on the top left of the target to make it centered
	x = target->getPosX() - (w / 2);
	y = target->getPosY() -(h / 2);


}
void Camera::update() {
	//follow target until it hits the wall
	x = target->getPosX()  - (w / 2) ;
	y = target->getPosY()  - (h / 2) ;
	if (x <= 0) {
		x = 0;
	}
	
}

