#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
	ifstream in("integral membranes.fasta");
	ofstream out("integral membranes.txt");
	string m,line="\0";
	int i=0;
	while(getline(in,m))
	{
		if(m[0]!='>')
			line = line+m;
		if(m[0]=='>')
		{
			out<<'>'<<'\n'<<line<<endl;
			line = "\0";
		}
	}
	in.close ();
	out.close ();

	return 0;
}
