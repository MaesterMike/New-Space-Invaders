#include "player.h"
#include "GameState.h"
#include "declconst.h"

int main()
{
	sfw::initContext(WINDOW_WIDTH,
		             WINDOW_HEIGHT,
		            "Invaders From Space");

	GameState gs;

	while (sfw::stepContext() && !sfw::getKey(KEY_ESCAPE))
	{
		gs.update();
		gs.draw();
	}
	
	sfw::termContext();
	return 0;
}