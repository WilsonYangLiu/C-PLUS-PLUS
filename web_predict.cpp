#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#define NUM 68  // the number of the sorted, optimal dipeptide
#define MAX 100 // the max number of sequence
using namespace std;

int main(int argc, char *argv[])
{
    const char AA[20] = {'G','A','V','L','I','P','F','Y','W','S','T','C','M','N','Q','D','E','K','R','H'};
    // ��ȡ���������ɸѡ����Ķ�������Ӧ�ı��
    int index[NUM];
    ifstream in("./sort_DPC.txt");
    for(int i = 0; i < NUM; i++)
        in>>index[i];
    in.close();
    // ���浰��������
    string protein[MAX];
    for(int p = 0; p < argc-1; ++p){
        protein[p] = argv[p+1];
    }
    cout<<"hi";
    // ��¼ÿ������������ĳ��ֵĴ���
    int count_DP[MAX][20][20];
    for(int p = 0; p < argc-1; ++p){
        for(int q = 0; q < protein[p].size(); ++q){
            int i = 0, j = 0;
            for(i = 0; i < 20; ++i){
                if(protein[p][q+0] == AA[i])break;
            }
            for(j = 0; j < 20; ++j){
                if(protein[p][q+1] == AA[j]) break;
            }
            ++count_DP[p][i][j];
        }
    }
    // �������������������ϳ��ֵĸ���
    double f[MAX][NUM];
    for(int p = 0; p < argc-1; ++p){
        int i = 0, j = 0;
        for(int q = 0; q < NUM; ++q){
            i = (index[q]-1)/20;
            j = (index[q]-1)-i*20;
            f[p][q] = (double)count_DP[p][i][j]/(protein[p].size()-1);
        }
    }
    // ���������������ɵĽ��
    ofstream out("./out");
    for(int p = 0; p < argc-1; ++p)
	{
		out<<fixed<<"1"<<' ';
		for(int q = 0; q < NUM; ++q)
			out<<q+1<<':'<<f[p][q]<<' ';
		out<<endl;
	}
	out.close();

    return 0;
}
