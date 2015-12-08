#include "sfwdraw.h"
#include "GameState.h"
#include "declconst.h"

void GameState::update()
{
	player.update();
}

void GameState::draw()
{
	player.draw();
}