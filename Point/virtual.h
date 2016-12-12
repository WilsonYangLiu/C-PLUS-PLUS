#include<iostream>

class Base
{
    public:
        int data;
};
class Derive11:virtual public Base
{

};
class Derive12:virtual public Base
{

};
class Derive2:public Derive11,public Derive12
{

};
