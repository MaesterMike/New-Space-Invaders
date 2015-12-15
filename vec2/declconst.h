#pragma once

#define WINDOW_WIDTH  800
#define WINDOW_HEIGHT 600

#define BOUNDS_TOP    570
#define BOUNDS_BOTTOM 30
#define BOUNDS_LEFT   10
#define BOUNDS_RIGHT  790

#define ORANGE 0xffA500ff;

#define TITLE "Invaders from Space!"

class GameState;

//declaration
extern unsigned spriteSpace;
extern unsigned spritePlayer;
extern unsigned spriteBullet;
extern unsigned spriteEnemy;
extern unsigned spriteOtherEnemy;
extern unsigned spriteFont;
extern unsigned spriteExplosion;

enum STATE {SPLASH, PLAY, GAME, PAUSE, VICTORY, QUIT, HELP};

extern STATE applicationState;

void drawFontCentered(unsigned sprite, const char* text, unsigned x, unsigned y,
	unsigned w, unsigned h, unsigned color = 0xffffffff);