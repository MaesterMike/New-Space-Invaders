#pragma once
#include "GameObject.h"
#include "sfwdraw.h"

class bullet : public GameObject
{
public:
	float lifespan;

	bullet(float x, float y, float a_speed)
		: GameObject(x, y, 12), lifespan(3.f)
	{
		speed = a_speed;
		color = CYAN;
		velocity.y = speed;
	}

	void onUpdate()
	{
		lifespan -= sfw::getDeltaTime();
		if (lifespan < 0) active = false;
	}
};