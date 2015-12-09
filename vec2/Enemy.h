#pragma once
#include "GameObject.h"
#include "sfwdraw.h"

class Enemy : public GameObject
{
public:
	float delay, rof;
	Enemy(float x, float y)
		: GameObject(x, y, 34), delay(0), rof(1.2f)
	{
		color = RED;
		speed = 150;
		velocity.y = -speed;
	}

	void onCollision(GameObject &o);
	
	void onUpdate();
};