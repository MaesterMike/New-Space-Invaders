#include "player.h"
#include "GameState.h"
#include "declconst.h"

int main()
{
	sfw::initContext(WINDOW_WIDTH,
		             WINDOW_HEIGHT,
		            "Invaders From Space");

	sfw::loadTextureMap("./textures/Space.jpeg");
	sfw::loadTextureMap("./textures/Player.png");
	sfw::loadTextureMap("./textures/bullet.png");
	sfw::loadTextureMap("./textures/Enemy.gif");
	sfw::loadTextureMap("./textures/OtherEnemy.gif");
	sfw::loadTextureMap("./textures/Explosions.png");

	GameState gs;

	while (sfw::stepContext() && !sfw::getKey(KEY_ESCAPE))
	{
		gs.update();
		gs.draw();
	}
	
	sfw::termContext();
	return 0;
}