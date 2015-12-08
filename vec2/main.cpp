#include <iostream>
#include "player.h"
#include "GameState.h"
#include "sfwdraw.h"
#include "declconst.h"

int main()
{
	sfw::initContext(WINDOW_WIDTH,
		             WINDOW_HEIGHT,
		            "Invaders From Space");

	Player go((BOUNDS_RIGHT+BOUNDS_LEFT)/2,
		                         BOUNDS_BOTTOM);

	GameState gs;

	while (sfw::stepContext())
	{
		go.update();
		go.draw();
	}
	
	sfw::termContext();
	return 0;
}