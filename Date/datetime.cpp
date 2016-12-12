#include<iostream>
#include<cstdlib>
#include "test.h"

using namespace std;

int main()
{
    Date d(2003,10,10);
    Time t(10,11,60);
    DateTime(d,t);
    return 0;
}
