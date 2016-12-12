#include<iostream>
#include<fstream>
#include<cstring>

#define instance 404
#define atribute 196

using namespace std;

int main()
{
    ifstream txt("./OPD");
    if(!txt)
    {
        cout<<"can't open file OPD!"<<endl;
    }

    double data[instance][atribute]={};
    for(int i=0;i<instance;i++)
    {
        for(int j=0;j<atribute;j++)
        {
            txt>>data[i][j];
        }
    }
    txt.close();

    char ch[100];
    for(int i=0;i<atribute;i++)
    {
        sprintf(ch,"./arff/arff%d.arff",i+1);
        //cout<<ch;getchar();
        ofstream arff(ch);
        if(!arff)
        {
            cout<<"the file arff can't open!"<<endl;
        }
        arff<<"% Annotation"<<'\n'<<"@relation "<<i+1<<"atribute"<<endl;
        for(int k=0;k<i+1;k++)
        {
            arff<<"@attribute "<<k+1<<" numeric"<<endl;
        }
        arff<<"@attribute Class {1,2}"<<'\n'<<"@Data"<<endl;
        for(int j=0;j<instance;j++)
        {
            for(int k=0;k<i+1;k++)
            {
                arff<<data[j][k]<<',';
            }
            if(j<178)
            {
                arff<<'1'<<endl;
            }
            else
            {
                arff<<'2'<<endl;
            }
        }
        arff.close();

    }




    return 0;
}
