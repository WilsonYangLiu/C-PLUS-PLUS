#include<cstdlib>
#include<curses.h>
#include"settings.h"
#include"screen.h"

void PrintScreen()
{
	box(stdscr,0,0);
	//wborder(stdscr,'0','1','2','3','4','5','6','7');
	mvaddstr(1,10,"A easy game");
	for(int i=1; i<COLS-1; i++)
		mvaddch(2,i,'-');
}
void GameOver()
{
	SetTicker(0);
	clear();
	mvaddstr(LINES/2,COLS/2-5,"Game Over");
	refresh();
	getchar();
	WrapUp();
	exit(1);
}
