#pragma once
#include "GameObject.h"

class Player : public GameObject
{
public:
	Player(float x, float y)
		: GameObject(x,y,35)
	{
		speed = 250;
	}

	void onUpdate();
};