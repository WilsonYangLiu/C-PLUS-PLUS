#include<iostream>
#include "virtual.h"
#include "Point.h"

using namespace std;

int main()
{
    Rectangle rec(1,1,1,2);
    Rectangle a(rec);
    rec.ShowRec();
    a.ShowRec();

    return 0;
}
