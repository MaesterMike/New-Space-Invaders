#include "player.h"
#include "sfwdraw.h"
#include "declconst.h"

void Player::onUpdate()
{
	velocity = { 0,0 };

	if (sfw::getKey(KEY_LEFT))
	{
		velocity.x = -speed;
	}

	if (sfw::getKey(KEY_RIGHT))
	{
		velocity.x = speed;
	}

	if (sfw::getKey(KEY_DOWN))
	{
		velocity.y = -speed;
	}

	if (sfw::getKey(KEY_UP))
	{
		velocity.y = speed;
	}

	if (position.x - radius < BOUNDS_LEFT)
	{
		position.x = BOUNDS_LEFT + radius;
	}

	if (position.x + radius > BOUNDS_RIGHT)
	{
		position.x = BOUNDS_RIGHT - radius;
	}
}