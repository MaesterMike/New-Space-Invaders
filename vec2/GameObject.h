#pragma once
#include "vec2.h"
#include "sfwdraw.h"
#include "declconst.h"

class GameObject
{
public:
	static GameState *gs;

	vec2 position, velocity;
	float radius;
	unsigned color;
	unsigned sprite;
	float speed;
	bool active;

	GameObject::GameObject(float x, float y, float radius)
		: position({ x, y }), speed(0), color(MAGENTA),
		  velocity({ 0, 0 }), radius(radius), active(true),
		sprite(spriteExplosion)
	    { }

	void update();
	void draw();

	void setInactive()
	{
		if (!active) return;
		active = false;
		onInactive();
	}

	virtual void onInactive() {}

	virtual void onUpdate()   {}
	virtual void onDraw()     {}
	virtual void onCollision(GameObject &o) {}
};

void collides(GameObject &a, GameObject &b);