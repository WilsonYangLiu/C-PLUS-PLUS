#include<iostream>
#include<memory.h>
#include "intset.h"

using namespace std;

int main()
{
    intSet A;
#if 1
    A.Add(-100);
    A.Add(24);
    A.Print();
    intSet B(A);
//    B.Print();
#endif

    return 0;
}
