#include<iostream>
#include<csignal>
#include<curses.h>
#include"ball.h"
ball *ball::pBall = NULL;
ball::ball(int x, int y)
{
	y_pos = y;
	x_pos = x;
	y_dir = 1;
	x_dir = 1;
	symbol = DFL_SYMBOL;
}
ball::~ball()
{
}
void ball::Init()
{
	mvaddch(y_pos, x_pos, symbol);
	refresh();
}
int ball::BounceLose()
{
	int return_val = 0;
	if(y_pos==TOP_ROW)
	{
		y_dir = 1;
		return_val = 1;
	}
	else if(y_pos==BOT_ROW)
	{
		y_dir = -1;
		return_val = 1;
	}
	if(x_pos==LEFT_EDGE)
	{
		x_dir = 1;
		return_val = 1;
	}
	else if(x_pos==RIGHT_EDGE)
	{
		x_dir = -1;
		return_val = 1;
	}
	return return_val;
}
bool ball::Fail(bar &theBar)
{
//	char s[10];
//	sprintf(s,"%d",theBar.x_pos);
//	mvaddstr(10,10,"     ");
//	mvaddstr(10,10,s);
	if(y_pos==BOT_ROW)
	{
		if(x_pos<theBar.x_pos||x_pos>theBar.x_pos+theBar.len)
			return true;
		else
			return false;
	}
	return false;	
}

void ball::Move(int signum)
{
	int y_cur, x_cur, moved;

	signal(SIGALRM, SIG_IGN);			/* don't get caught now	*/

	y_cur = pBall->y_pos;
	x_cur = pBall->x_pos;
	moved = 0;
	
	pBall->y_pos += pBall->y_dir;
	pBall->x_pos += pBall->x_dir;

	mvaddch(y_cur, x_cur, BLANK);
	mvaddch(pBall->y_pos, pBall->x_pos, pBall->symbol);
	pBall->BounceLose();
	if(pBall->Fail(mybar))
		GameOver();
	move(LINES-1, COLS-1);
	refresh();

	//signal(SIGALRM, SIG_IGN);
	signal(SIGALRM, ball::Move);
}
