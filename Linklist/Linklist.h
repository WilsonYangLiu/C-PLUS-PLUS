#include<iostream>
#include<cstdlib>
#include<memory.h>

typedef int status;
typedef int elementype;
struct node
{
    elementype data;
    struct node *next;
};
//--create---
status createlist(struct node *l,int n)
{
    struct node *p, *q;
    int i;
    q = l;
    for(i=0;i<=n;i++)
    {
        p = (node*)malloc(sizeof(struct node));
        if(!p)
        {
            std::cout<<"memory overflow"<<std::endl;
            return 0;
        }
        std::cout<<"input linked list:"<<std::endl;
        std::cin>>p->data;
        q->next = p;
        q = p;
    }
    q->next = NULL;
    return 1;
}
//--Print---
void printlist(struct node *l)
{
    struct node *p;
    int i=0;
    p = l->next;
    while(p)
    {
        i++;
        std::cout<<"this is the "<<i<<"-th node: "<<p->data<<std::endl;
        p = p->next;
    }
}
//--Get element---
status getelem(struct node *l,int i)
{
    struct node *p;
    int j=1;
    p = l->next;
    while(p&&j<i)
    {
        p = p->next;
        j++;
    }
    if(!p||j>i)
    {
        std::cout<<"i error"<<std::endl;
        return 0;
    }
    return p->data;
}
//--clear---
void listclear(struct node *l)
{
    struct node *q,*p;
    p = l->next;
    while(p)
    {
        q = p;
        p = p->next;
        free(q);
    }
}
//--list insert---
status listinsert(struct node *l,int i,elementype e)
{
    struct node *p,*s;
    int j=0;
    p = l;
    while(p&&j<i-1)
    {
        p = p->next;
        j++;
    }
    if(!p||j>i-1)
    {
        std::cout<<"i error"<<std::endl;
        return 0;
    }
    s = (struct node *)malloc(sizeof(struct node));
    s->data = e;
    s->next = p->next;
    p->next = s;
    p = l;
    printlist(p);
    std::cout<<'\n';
    return 1;
}
//--delete element---
status listdelete(struct node *l,int i)
{
    struct node *p,*q;
    int j,e;
    p = l;j = 0;
    while(p->next&&j<i-1)
    {
        p = p->next;
        j++;
    }
    if(!(p->next)||j>i-1)
    {
        std::cout<<"i error"<<std::endl;
        return 0;
    }
    q = p->next;p->next = q->next;
    free(q);
    p = l;
    printlist(p);
    std::cout<<'\n';
    return 1;
}
