#include "GameObject.h"
#include "sfwdraw.h"

GameState *GameObject::gs;

void GameObject::update()
{
	if (!active) return;
	position = eulerIntegrate(position, velocity, sfw::getDeltaTime());

	onUpdate();
}

void GameObject::draw()
{
	if (!active) return;
	sfw::drawCircle(position.x, position.y, radius, 12, color);

	onDraw();
}

void collides(GameObject &a, GameObject &b)
{
	if(a.active && b.active)
		if (circleOverlap(a.position, a.radius,
		                  b.position, b.radius))
		{ 
			a.onCollision(b);
			b.onCollision(a);
		}
}