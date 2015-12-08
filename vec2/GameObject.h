#pragma once
#include "vec2.h"

class GameObject
{
public:
	vec2 position, 
		 velocity;
	float radius;

	float speed;

	GameObject::GameObject(float x, float y, float radius)
		: position({ x, y }), 
		  velocity({ 0, 0 }), radius(radius)
	    { }

	void update();
	void draw();

	virtual void onUpdate() {}
	virtual void onDraw() {}
};