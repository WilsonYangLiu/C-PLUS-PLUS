#ifndef BALL_H
#define BALL_H
#include<curses.h>
#include"bar.h"
#include"screen.h"

extern bar mybar;
class ball
{
public:
	int y_pos, x_pos,
		y_dir, x_dir;
	char symbol;
	ball(int x = 10, int y = 10);
	~ball();
	void Init();	
	
	int BounceLose();
	bool Fail(bar&);	
	
	static void Move(int);
	static ball *pBall;
};

const char BLANK = ' ';
const char DFL_SYMBOL = 'o';
const int  TICKS_PER_SEC = 50;

enum sides{TOP_ROW = 3, BOT_ROW = 20, LEFT_EDGE = 5, RIGHT_EDGE = 75,};

#endif
