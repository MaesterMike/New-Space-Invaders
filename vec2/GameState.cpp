#include "GameState.h"

void GameState::update()
{
	spawnDelay += sfw::getDeltaTime();
	if (spawnDelay > spawnRate)
	{
		spawnDelay = 0;
		spawnRate *= .98f;
		spawnEnemy(randRange(BOUNDS_LEFT, BOUNDS_RIGHT), BOUNDS_TOP);
	}

	player.update();
	for (int i = 0; i < Bullets.size(); ++i)
		Bullets[i].update();
	for (int i = 0; i < Enemies.size(); ++i)
		Enemies[i].update();
	for (int i = 0; i < particles.size(); ++i)
		particles[i].update();

	// Player vs Bullets
	for (int i = 0; i < Bullets.size(); ++i)
		collides(player, Bullets[i]);
	for (int i = 0; i < Enemies.size(); ++i)
		collides(player, Enemies[i]);

	// For every bullet and every enemy,
	for (int i = 0; i < Enemies.size(); ++i) // For each enemy
		for (int j = 0; j < Bullets.size(); ++j) // For every bullet
			collides(Enemies[i], Bullets[j]);

	for (int i = 0; i+1 < Enemies.size(); ++i)
		for (int j = i+1; j < Bullets.size(); ++j)
			collides(Enemies[i], Bullets[j]);
}

void GameState::draw()
{
	sfw::drawTexture(spriteSpace, WINDOW_WIDTH, WINDOW_HEIGHT);

	player.draw();
	for (int i = 0; i < Bullets.size(); ++i)
		Bullets[i].draw();
	for (int i = 0; i < Enemies.size(); ++i)
		Enemies[i].draw();
	for (int i = 0; i < particles.size(); ++i)
		particles[i].draw();
}

void GameState::spawnParticle(float x, float y, float a_startRadius, float a_endRadius,
	float a_lifetime, unsigned a_color)
{
	Particle b(x, y, a_startRadius, a_endRadius, a_lifetime, a_color);

	for (int i = 0; i < particles.size(); ++i)
		if (!particles[i].active)
		{
			particles[i] = b;
			return;
		}
	particles.push_back(b);
}

void GameState::spawnBullet(float x, float y, float a_speed)
{
	bullet b(x, y, a_speed);

	for (int i = 0; i < Bullets.size(); ++i)
		if (!Bullets[i].active)
		{
			Bullets[i] = b;
			return;
		}
	Bullets.push_back(b);
}

void GameState::spawnEnemy(float x, float y)
{
	Enemy e(x, y);

	for (int i = 0; i < Enemies.size(); ++i)
		if (!Enemies[i].active)
		{
			Enemies[i] = e;
			return;
		}
	Enemies.push_back(e);
}