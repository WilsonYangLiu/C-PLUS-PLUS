#include<iostream>
#include<cstdlib>
#include "test.h"

using namespace std;

int main()
{
    Date date1;          //--不给予参数date1()时，没有调用？date1调用默认构造函数---
    Date *date2,*date3;
    const Date dateconst(2014,5,9);
    dateconst.GetDate();
    //Date &date4 = date1,&date5=date1;
    //date4.Print();date5.Print();
    date2 = new Date(1999);         //--一个具体的类对象跟对象指针的关系----
    date3 = new Date[2];
    //date1.Display(date1);
    Date::Display(date1);
    date1.GetDate();
    date1.Set(1990,1,1).Display(date1);
    date2->Display(*date2);
    //*date2.Print();                 //--解引用将发生错误---
    date3[0].Print();
    date3->Print();
    (*(date3+1)).Print();
    delete[] date3;
    delete date2;

    //Test test1;
    //test1.Print();


    return 0;
}


