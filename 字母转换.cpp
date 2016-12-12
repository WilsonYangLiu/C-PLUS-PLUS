#include<iostream>
#include<string>
#include<cstring>
#include<fstream>
using namespace std;

int main()
{
	char ch;
	int length;
	string str;
	ifstream in("in.txt");
	ofstream out("out.txt");
	in>>str;
	length = str.length(); 
	ch = str[0];
	for(int i=0;i<length;)
	{
		if(ch>47 && ch<58) {i++;ch=str[i];continue;}
		if(ch>96 && ch<123) str[i] = ch-32;
		if(ch>64 && ch<91) str[i] = ch+32;
		i++;
		ch=str[i];
	}
	out<<str<<endl;
	cout<<str<<endl;
	return(0);
}

		

