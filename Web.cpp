#include<iostream>
#include<string>
#include<cstring>
#include<fstream>
#include<iomanip>
#include<cmath>
#includec<stdlib.h>

#define number 1040//mark 注意修改
using namespace std;

int main(int argc,char *argv[])
{
	static char AA[20]={'G','A','V','L','I','P','F','Y','W','S','T','C','M','N','Q','D','E','K','R','H'};
	//--------------------------------记录特征三肽对应的标号-------------------------
	static int a[number]={0};
	ifstream in(".\\a.txt");
	for(int i=0;i<number;i++) in>>a[i];
	in.close();
	//cout<<a[1039];getchar();
	//-----------------------贮存蛋白质序列，同时记录每一条序列的长度，阈值设为100----------------
	int len[100]={0};
	string protien[100];
	for(i=0;i<argc-1;i++){protien[i] = argv[i+1];len[i] = protien[i].length();}
	//-----------------------记录8000种三肽在每一条序列各自出现的次数----------------------
	static int count[100][20][20][20]={0};
	for(int q=0;q<argc-1;q++)
		for(int ss=0;ss<len[q]-2;ss++)
		{
			for(i=0;i<20;i++)
				if(protien[q][ss]==AA[i])break;
			for(int j=0;j<20;j++)
				if(protien[q][ss+1]==AA[j])break;
			for(int k=0;k<20;k++)
				if(protien[q][ss+2]==AA[k])break;
			count[q][i][j][k]++;
			//cout<<i<<' '<<j<<' '<<k<<' '<<count[q][i][j][k]<<' ';getchar();
		}
	//-----------计算特征三肽在序列上出现的概率---------------------
	int k=0,j=0;
	static double f[100][8000];
	for(q=0;q<argc-1;q++)
	{
		for(int p=0;p<number;p++)
		{
			//cout<<a[p]<<' ';
			i = a[p]/400;
			j = (a[p]-i*400)/20;
			k = a[p]-i*400-j*20;
			f[q][p] = (double)count[q][i][j][k]/(len[q]-2);
			//cout<<i<<' '<<j<<' '<<k<<' '<<f[q][p]<<' '<<len[q];getchar();
		}
	}
	//---------------输出有特征参数组成的结果----------------
	ofstream out("out");
	for(q=0;q<argc-1;q++)
	{
		out<<fixed<<"1"<<' ';
		for(i=0;i<number;i++)
			out<<i+1<<':'<<f[q][i]<<' ';
		out<<endl;
	}
	//-----------------调用SVM----------------------------
	system(".\\svm-scale.exe -r rule out>out.scale");
	system(".\\svm-predict.exe -b 1 out.scale model result.txt");

	return 0;
}
