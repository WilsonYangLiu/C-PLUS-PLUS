#include<iostream>
#include<cstdlib>
#include<memory.h>

typedef int Status;
//--struct---
#define INITSIZE 100
#define INCREMEMT 10
typedef int elementype;
struct sqlist
{
    elementype *elem;
    int length;
    int listsize;
};
//--Initialization---
void initlist(sqlist &l)
{
    l.elem = (elementype*)malloc(INITSIZE*sizeof(elementype));
    if(!l.elem)
        std::cout<<"overflow"<<std::endl;
    else
    {
        l.length = 0;
        l.listsize = INITSIZE;
        memset(l.elem,0,INITSIZE*sizeof(elementype));
        std::cout<<"ok!"<<std::endl;
    }
}
//--Locate---
Status localeelem(sqlist l,elementype x)
{
    int i;
    elementype *p;
    i = 1;
    p = l.elem;
    while(i<=l.length&&(*p++)!=x)
        ++i;
    if(i<=l.length) return i;
    else return 0;
}
//--Insert---
Status listinsert(sqlist &l,int i,elementype e)
{
    elementype *p,*q,*newbase;
    if(i<1||i>l.length+1)
    {
        std::cout<<"i error"<<std::endl;
        return 0;
    }
    if(l.length>=l.listsize)
    {
        newbase = (elementype*)realloc(l.elem,(l.listsize+INCREMEMT)*sizeof(elementype));
        if(!newbase)
        {
            std::cout<<"overflow"<<std::endl;
            return 0;
        }
        l.elem = newbase;
        l.listsize += INCREMEMT;
    }
    q = &(l.elem[i-1]);
    for(p=&(l.elem[l.length-1]);p>=q;p--)
        *(p+1) = *p;
    //std::cout<<"fuck"<<std::endl;
    *q = e;
    l.length++;
    std::cout<<"ok!"<<std::endl;
    return 1;
}
//--if Empty?---
Status listempty(sqlist l)
{
    if(l.length==0)
        return 1;
    else
        return 0;
}
//--Clear---
void listclear(sqlist &l)
{
    l.length = 0;
}
//--Length---
int listlength(sqlist &l)
{
    return l.length;
}
//--Delete---
Status listdelete(sqlist &l,int i)
{
    elementype e,*p,*q;
    if(i<0||i>l.length)
    {
        std::cout<<"i error"<<std::endl;
        return 0;
    }
    p = &(l.elem[i-1]);
    e = *p;
    q = l.elem+l.length-1;
    for(++p;p<=q;p++)
        *(p-1) = *p;
    --l.length;
    std::cout<<"ok!"<<std::endl;
    return 1;
}

