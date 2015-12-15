#pragma once
#include "GameObject.h"

class Particle : public GameObject
{
public:
	float startRadius, endRadius;
	float lifespan, lifetime;

	Particle(float x, float y, 
		float a_startRadius, float a_endRadius, 
		float a_lifetime, unsigned a_color)
		
		: GameObject(x, y, a_startRadius), 
		endRadius(a_endRadius), startRadius(a_startRadius),
		lifespan(0), lifetime(a_lifetime)
	{
		sprite = spriteExplosion;
		color = a_color;
	}

	void onUpdate()
	{
		radius = lerp(startRadius, endRadius, lifespan / lifetime);
		lifespan += sfw::getDeltaTime();
		if (lifespan > lifetime) active = false;
	}
};