#include<iostream>
#include<cmath>
using namespace std;

double Binomial(int n,int m,double p)
{
	double t = 1;
	for(int i=0; i<m ; i++)
	{
		t *= (double)(n-i) * p / (double)(m-i);
	}
	return t*pow(1-p,n-m);
}

int main()
{
	int n, m;
	double p;
	cout<<"ÊäÈën£¬m£¬p£º";
	cin>>n>>m>>p;
	if(n>=m)
	{cout<<Binomial(n,m,p)<<endl;return 0;}
	else
		return 0;
}
