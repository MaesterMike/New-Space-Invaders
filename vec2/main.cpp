#include "player.h"
#include "GameState.h"
#include "declconst.h"
#include "SplashState.h"
#include "PauseState.h"
#include "Victory.h"

//definition
unsigned spriteSpace;
unsigned spritePlayer;
unsigned spriteBullet;
unsigned spriteEnemy;
unsigned spriteOtherEnemy;
unsigned spriteFont;
unsigned spriteExplosion;

STATE applicationState = SPLASH;

int main()
{
	sfw::initContext(WINDOW_WIDTH,
		             WINDOW_HEIGHT,
		            "Invaders From Space!");
	
	//initialization
	spriteSpace  = sfw::loadTextureMap("./textures/Space.jpg");
	spritePlayer = sfw::loadTextureMap("./textures/Player.png");
	spriteBullet = sfw::loadTextureMap("./textures/bullet.png");
	spriteEnemy  = sfw::loadTextureMap("./textures/redEnemy.png");
	spriteOtherEnemy = sfw::loadTextureMap("./textures/blueEnemy.png");
	spriteFont = sfw::loadTextureMap("./textures/Font.png",16,16);
	spriteExplosion = sfw::loadTextureMap("./textures/Explosion.png");

	
	GameState gs;
	SplashState ss;
	PauseState ps;
	VictoryState vs;

	while (sfw::stepContext() && !sfw::getKey(KEY_ESCAPE))
	{
		switch (applicationState)
		{
		case SPLASH:
			ss.update();
			ss.draw();
			break;
		case PLAY:
			gs.reset();
			applicationState = GAME;
		case GAME:
			gs.update();
			gs.draw();
			break;
		case PAUSE:
			gs.draw();
			ps.update();
			ps.draw();
			break;
		case VICTORY:
			gs.update();
			gs.draw();
			vs.update();
			vs.draw();
			break;
		}
	}
	
	sfw::termContext();
	return 0;

	system("pause");
}

void drawFontCentered(unsigned sprite, const char* text, unsigned x, unsigned y, 
	unsigned w, unsigned h, unsigned color)
{
	x -= strlen(text) * w / 2;
	sfw::drawString(spriteFont, text, x, y, w, h, 0, 0, color);
}