#include<iostream>
#include<fstream>
#include"myregexp.h"

using namespace std;

int main(int argc, char *argv[])
{
    if(argc==1) exit_with_help();
    for(int i=1;i<argc;i++)
	{
		if(argv[i][0] != '-') break;
		++i;
		switch(argv[i-1][1])
		{
			default:
				fprintf(stderr,"unknown option\n");
				exit_with_help();
		}
	}
	char *regexp = new char[];
    if(argv[1][1] == 'r')
    {
        fprintf(regexp,"%s",argv[2]);
    }
    if(argv[3][1] == 'r')
    {
        fprintf(regexp,"%s",argv[2]);
    }


	return 0;
}
