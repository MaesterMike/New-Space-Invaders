#pragma once
#include "GameObject.h"

class Player : public GameObject
{
public:
	float delay, rof;
	int health;
	bool firingKeyState;

	Player(float x, float y)
		    : GameObject(x,y,35),
		      delay(0), rof(0.1f),
		      health(3), firingKeyState(false)
	{
		color = GREEN;
		speed = 250;
	}

	void onUpdate();
	void onCollision(GameObject &o);
	void onInactive();
};