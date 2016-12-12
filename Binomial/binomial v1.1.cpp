#include<iostream>
#include<cmath>
using namespace std;

double Binomial(int n,int m,double p)
{
	double t=1;
	int k=0, a=0, x=0;
	//---------------��n,m,p�����Ե��ж�---------------
	if(n<m)
	{
		cout<<"You must let n >= m!"<<endl;
		exit(0);
	}
	if(p<0||p>1)
	{
		cout<<"The p is between 0 and 1!"<<endl;
		exit(0);
	}
	//---------------����ֲ�-------------------
	k=n-m;
	if(k>n/2)
	{
		a=k-m; x=1;
		while(a>m)
		{
			x++;
			a=a-m;
		}
		for(int i=0; i<m; i++)
			t*=(double)(n-i)*p*pow(1-p,x)/(double)(m-i);
		return t*pow(1-p,a);
	}
	else
	{
		int i;
		a=m-k;
		for(i=0; i<a; i++)
			t*=(double)(n-i)*p/(double)(m-i);
		for(; i<m; i++)
			t*=(double)(n-i)*p*(1-p)/(double)(m-i);
		return t;
	}

}

int main()
{
	int n, m;
	double p;
	cout<<"����n��m��p��";
	cin>>n>>m>>p;
	cout<<Binomial(n,m,p)<<endl;
	return 0;
}
