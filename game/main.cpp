#include<iostream>
#include<curses.h>
#include<sys/time.h>
#include<csignal>
#include"ball.h"
#include"bar.h"
#include"settings.h"
#include"screen.h"
using namespace std;

bar mybar(20,30);
int main()
{
	int c;
	ball ballA(20,15), ballB;
	
	SetUp();
	
	PrintScreen();
	
	bar testbar(5,20);
	
	testbar.Init();
	
	//signal(SIGINT, SIG_IGN);
	//signal(SIGALRM, SIG_IGN);
	
	ball::pBall = &ballA;	
	signal(SIGALRM, ball::Move);
	ball::pBall = &ballB;	
	signal(SIGALRM, ball::Move);
	SetTicker(1500/TICKS_PER_SEC);

	while((c=getchar())!='Q')
	{
		if(c=='a')
		{
			testbar.Left();//left
			mybar=testbar;
		}
		if(c=='d')
		{
			testbar.Right();//right
			mybar=testbar;
		}
		if(c=='g')
		{	
			GameOver();
		}
	}

	WrapUp();

	return 0;
}
