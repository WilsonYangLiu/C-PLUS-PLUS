#include<curses.h>
#include"bar.h"
bar::bar(int l, int x)
{
	len = l;	
	x_pos = x;
	y_pos = LINES - 3;
	if(x_pos<1)
		x_pos = 1;
	if(x_pos>COLS-1-len)
		x_pos = COLS-1-len;
	symbol = '~';
}
bar::~bar()
{
}
void bar::Init()
{
	for(int i=0; i<len; i++)
		mvaddch(y_pos, x_pos +i, symbol);
	move(LINES-1, COLS-1);
	refresh();
}
void bar::Left()
{
	if(x_pos == 1)
		return;
	for(int i=0; i<len; i++)
		mvaddch(y_pos, x_pos +i, ' ');
	x_pos--;
	for(int i=0; i<len; i++)
		mvaddch(y_pos, x_pos +i, symbol);
	move(LINES-1, COLS-1);
	refresh();
}
void bar::Right()
{
	if(x_pos == COLS-1-len)
		return;
	for(int i=0; i<len; i++)
		mvaddch(y_pos, x_pos +i, ' ');
	x_pos++;
	for(int i=0; i<len; i++)
		mvaddch(y_pos, x_pos +i, symbol);
	move(LINES-1, COLS-1);
	refresh();
}
