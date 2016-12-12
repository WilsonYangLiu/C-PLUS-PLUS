#include<iostream>
#include "Linklist.h"

using namespace std;

int main()
{
    node *l;
    l = (node*)malloc(sizeof(node));
    if(!l) cout<<"error"<<endl;
    l->next = NULL;
    createlist(l,5);
    printlist(l);
    return 0;
}
