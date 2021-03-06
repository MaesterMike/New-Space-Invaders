#pragma once
#include "player.h"
#include "declconst.h"
#include "bullet.h"
#include "Enemy.h"
#include <vector>
#include "Particle.h"

class GameState
{
public:
	Player player;
	std::vector<bullet> Bullets;
	std::vector<Enemy> Enemies;
	std::vector<Particle> particles;

	float spawnRate;
	float spawnDelay;
	unsigned score;

	GameState() :
		player((BOUNDS_RIGHT + BOUNDS_LEFT) / 2, BOUNDS_BOTTOM),
		spawnDelay(0), spawnRate(1.8f)
	{ 
		GameObject::gs = this;

		spawnEnemy(player.position.x, BOUNDS_TOP);
	}

	void reset()
	{
		score = 0;
		spawnDelay = 0;
		spawnRate = 1.8f;
		player = Player((BOUNDS_RIGHT + BOUNDS_LEFT) / 2, BOUNDS_BOTTOM);
		Bullets.clear();
		Enemies.clear();
		particles.clear();
	}

	void update();
	void draw();
	void spawnBullet(float x, float y, float a_speed);
	void spawnEnemy(float x, float y);
	void spawnParticle(float x, float y,
		float a_startRadius, float a_endRadius,
		float a_lifetime, unsigned a_color);
};