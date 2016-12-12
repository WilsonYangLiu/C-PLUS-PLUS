#include<iostream>
#include<fstream>
#include<vector>

#define row 2
#define column 40000

using namespace std;

int main()
{
    ifstream infile("./traned.txt");
    if(!infile)
    {
        cout<<"the file can not open!"<<endl;
    }
    ofstream outfile("./outfile");
    if(!outfile)
    {
        cout<<"the file out can not open!"<<endl;
    }

    int temp;
    infile>>temp;
    for(int i=0;i<row;i++)
    {
        outfile<<i<<'\t';
        infile>>temp;
        for(int j=0;j<column;j++)
        {
            if(j+1!=temp)
            {
                outfile<<j+1<<':'<<0<<'\t';
            }
            else
            {
                infile>>temp;
                outfile<<j+1<<':'<<temp<<'\t';
                infile>>temp;
            }
        }
        outfile<<endl;
    }

    return 0;
}
