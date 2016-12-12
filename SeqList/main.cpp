#include<iostream>
#include "SeqList.h"

using namespace std;

int main()
{
    struct sqlist l;
    initlist(l);
    cout<<l.elem<<' '<<l.length<<' '<<l.listsize<<endl;
    for(int i=0;i<10;i++)
        listinsert(l,1,i+6);
    //cout<<"fuck"<<endl;
    for(int i=0;i<10;i++)
        cout<<l.elem[i]<<'\n';
    cout<<localeelem(l,8)<<endl;
    cout<<listempty(l)<<endl;
    return 0;
}
