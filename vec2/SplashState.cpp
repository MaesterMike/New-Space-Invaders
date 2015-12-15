#include "SplashState.h"
#include <cstring>
#include <cmath>

void SplashState::update()
{
	float wave = (0xff * (cosf(sfw::getTime() * 4) + 1) / 2);
	color = baseColor + wave;

	if (sfw::getKey(KEY_ENTER))
		applicationState = PLAY;
	if (sfw::getKey(KEY_ESCAPE))
		applicationState = QUIT;
}

void SplashState::draw()
{
	sfw::drawTexture(spriteSpace, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2,
		WINDOW_WIDTH, WINDOW_HEIGHT);

	unsigned x, y, s;

	s = 32;
	x = (WINDOW_WIDTH) / 2;
	y = WINDOW_HEIGHT * 3 / 4;
	drawFontCentered(spriteFont, TITLE, x, y, s, s);

	s = 16;
	y = WINDOW_HEIGHT * 5 / 8;
	drawFontCentered(spriteFont, "Press Enter to start.", x, y, s, s, RED);
	drawFontCentered(spriteFont, "Press Escape to quit.", x, y - 20, s, s, RED);

	s = 12;
	x -= 200;
	y = WINDOW_HEIGHT * 8 / 16;
	sfw::drawString(spriteFont, "Use the Arrow Keys to move.", x, y -= 48, 16, 16);
	sfw::drawString(spriteFont, "Press the Space Bar to fire.", x, y -= 16, 16, 16);
	sfw::drawString(spriteFont, "Press the P key to pause.", x, y -= 16, 16, 16);
	sfw::drawString(spriteFont, "Press Escape to quit.", x, y -= 16, 16, 16);
}