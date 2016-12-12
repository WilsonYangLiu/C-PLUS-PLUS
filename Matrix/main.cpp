#include<iostream>
#include<fstream>
#include"Matrix.cpp"

using namespace std;

int main()
{
    ifstream ain("b.txt");
    Matrix m(3,3);
    Matrix b(2,1);
    b(0,0)=2,b(1,0)=1;
    ain>>m;
    cout<<m;
    inverse(m);
    cout<<m;


    ain.close();
    return 0;
}
