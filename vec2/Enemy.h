#pragma once
#include "GameObject.h"
#include "sfwdraw.h"

class Enemy : public GameObject
{
public:
	float delay, rof, trailDelay, trailRate;
	Enemy(float x, float y)
		: GameObject(x, y, 17), 
		delay(0), rof(1.2f),
		trailDelay(0), trailRate(.2f)
	{
		sprite = spriteEnemy;
		speed = 150;
		velocity.y = -speed;
	}

	void onCollision(GameObject &o);
	
	void onUpdate();

	void onInactive();
};