#include "player.h"
#include "sfwdraw.h"
#include "declconst.h"
#include "GameState.h"

void Player::onUpdate()
{
	velocity = { 0,0 };

	delay += sfw::getDeltaTime();
	if (sfw::getKey(' ') && delay > rof)
	{
		delay = 0;
		gs->spawnBullet(position.x, position.y, 300);
	}

	if (sfw::getKey(KEY_LEFT))
	{
		velocity.x = -speed;
	}

	if (sfw::getKey(KEY_RIGHT))
	{
		velocity.x = speed;
	}

	/*if (sfw::getKey(KEY_DOWN))
	{
		velocity.y = -speed;
	}

	if (sfw::getKey(KEY_UP))
	{
		velocity.y = speed;
	}*/

	if (position.x - radius < BOUNDS_LEFT)
	{
		position.x = BOUNDS_LEFT + radius;
	}

	if (position.x + radius > BOUNDS_RIGHT)
	{
		position.x = BOUNDS_RIGHT - radius;
	}

	if (position.y - radius < BOUNDS_BOTTOM)
	{
		position.y = BOUNDS_BOTTOM + radius;
	}

	/*if (position.y + radius > BOUNDS_TOP)
	{
		position.y = BOUNDS_TOP - radius;
	}*/
}

void Player::onCollision(GameObject &o)
{
	if (o.velocity.y < 0)
	{
		health--;
		o.active = false;
		radius /= 2;
		switch (health)
		{
		case 2: color  = YELLOW; break;
		case 1: color  = RED; break;
		case 0: active = false; break;
		}
	}
}