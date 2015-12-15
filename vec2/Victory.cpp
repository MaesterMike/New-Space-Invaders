#include "Victory.h"
#include <cstring>
#include <cmath>
#include <fstream>
#include <vector>
#include <string>

void VictoryState::update()
{
	float wave = (0xff * (cosf(sfw::getTime() * 4) + 1) / 2);
	color = baseColor + wave;

	if (sfw::getKey('R'))
		applicationState = SPLASH;
	if (sfw::getKey(KEY_ESCAPE))
		applicationState = QUIT;
}

void VictoryState::draw()
{
	sfw::drawTexture(spriteSpace, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2,
		WINDOW_WIDTH, WINDOW_HEIGHT);

	unsigned x, y, s;

	s = 24;
	x = (WINDOW_WIDTH) / 2;
	y = WINDOW_HEIGHT * 3 / 4;
	drawFontCentered(spriteFont, "You are dead and the world was conquered by aliens. Oh well.", x, y, 12, 12, RED);

	s = 18;
	y = WINDOW_HEIGHT * 5 / 8;
	drawFontCentered(spriteFont, "Press r to play again.", x, y - 50, 12, 12, BLUE);
	drawFontCentered(spriteFont, "Or, press Escape to quit.", x, y - 60, 12, 12, BLUE);

	std::fstream fin("scores.dat", std::ios_base::in);
	std::vector<unsigned> scores;
	unsigned highScore = 0;
	while (!fin.eof())
	{
		unsigned t;
		fin >> t;

		if (t > highScore) highScore = t;
		scores.push_back(t);
	}
	scores.pop_back();
	fin.close();

	y = WINDOW_HEIGHT / 2;
	s = 24;
	sfw::drawString(spriteFont, std::to_string(scores[scores.size() - 1]).c_str(),
		x + sin(sfw::getTime()) * 8, y, s, s, 0, 0, CYAN);

	s = 18;
	y = WINDOW_HEIGHT / 2 - scores.size() * s;
	for (int i = scores.size() - 1; i >= 0 && scores.size() - i; --i)
	{
		sfw::drawString(spriteFont, std::to_string(scores[i]).c_str(),
			                                                    x, y + 18 * i, s, s);
	}
}