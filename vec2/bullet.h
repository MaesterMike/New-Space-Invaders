#pragma once
#include "GameObject.h"
#include "sfwdraw.h"
#include <cmath>

class bullet : public GameObject
{
public:
	float lifespan;

	bullet(float x, float y, float a_speed)
		: GameObject(x, y, 12), lifespan(3.f)
	{
		speed = a_speed;
		sprite = spriteBullet;
		if(speed > 0)
			color = CYAN;
		else 
			color = ORANGE;
		velocity.y = speed;
	}

	void onUpdate()
	{
		lifespan -= sfw::getDeltaTime();
		position.x += sin(lifespan * 10) * 3;
		radius -= sfw::getDeltaTime() * 4;
		if (lifespan < 0) active = false;
	}
};