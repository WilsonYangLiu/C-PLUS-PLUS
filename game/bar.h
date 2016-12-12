#ifndef BAR_H
#define BAR_H

class bar
{
public:
	int len;
	int y_pos, x_pos;	
	char symbol;
	bar(int l = 10, int x = 10);
	~bar();
	void Init();
	void Left();
	void Right();
	
	static void Move(int);	
};

#endif
