#include "GameObject.h"
#include "sfwdraw.h"

void GameObject::update()
{
	position = eulerIntegrate(position, velocity, sfw::getDeltaTime());

	onUpdate();
}

void GameObject::draw()
{
	sfw::drawCircle(position.x, position.y, radius);

	onDraw();
}