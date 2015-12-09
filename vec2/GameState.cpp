#include "GameState.h"

void GameState::update()
{
	spawnDelay += sfw::getDeltaTime();
	if (spawnDelay > spawnRate)
	{
		spawnDelay = 0;
		spawnEnemy(randRange(BOUNDS_LEFT, BOUNDS_RIGHT), BOUNDS_TOP);
	}

	player.update();
	for (int i = 0; i < Bullets.size(); ++i)
		Bullets[i].update();
	for (int i = 0; i < Enemies.size(); ++i)
		Enemies[i].update();

	// Player vs Bullets
	for (int i = 0; i < Bullets.size(); ++i)
		collides(player, Bullets[i]);

	// For every bullet and every enemy,
	for (int i = 0; i < Enemies.size(); ++i) // For each enemy
		for (int j = 0; j < Bullets.size(); ++j) // For every bullet
			collides(Enemies[i], Bullets[j]);

	for (int i = 0; i < Enemies.size()-1; ++i)
		for (int j = i+1; j < Bullets.size(); ++j)
			collides(Enemies[i], Bullets[j]);
}

void GameState::draw()
{
	player.draw();
	for (int i = 0; i < Bullets.size(); ++i)
		Bullets[i].draw();
	for (int i = 0; i < Enemies.size(); ++i)
		Enemies[i].draw();
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