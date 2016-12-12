
class Time;
class Date
{
    private:
        int year,month,day;
        static int count;
    public:
        Date(int y=2000,int m=10,int d=1);      //--构造函数可以重载，可以设置默认参数----
        Date(const Date& d);
        ~Date() {std::cout<<"Destructor of Date: "<<year<<'-'<<month<<'-'<<day<<std::endl;}
        static void Display(const Date& p);
        int GetDate() const ;
        Date& Set(int ,int ,int );
        friend void DateTime(const Date& d,const Time& t);
        int IsLeapYear();   //
        void Print();       //
};                          //----";"cannot ignore----
int Date::count = 0;
inline void Date::Print()   //----在前面加上inline,可将成员函数定义内联函数,否则就成员函数的调用是按一般函数进行的---
{
    std::cout<<year<<'-'<<month<<'-'<<day<<std::endl;
    //std::cout<<this<<std::endl;
}
inline int Date::IsLeapYear()
{
    return (year%4==0 && year%100!=0)||(year%400==0);
}
Date& Date::Set(int y,int m,int d)
{
    year = y;
    month = m;
    day = d;
    return *this;
}
int Date::GetDate() const
{
    std::cout<<"const: "<<(year)<<'-'<<month<<'-'<<day<<std::endl;
}
void Date::Display(const Date& d)
{
    std::cout<<"static: "<<d.year<<'-'<<d.month<<'-'<<d.day<<std::endl;
    std::cout<<"There are(is) "<<count<<" date(s)."<<std::endl;
}
Date::Date(const Date& d)
{

    year = d.year;
    month = d.month;
    day = d.day;
    std::cout<<"Copy Constructor of Date."<<std::endl;
}
Date::Date(int y,int m,int d):year(y),month(m),day(d)
{
    count++;
    std::cout<<"Constructor of Date with 1~3 parameter."<<std::endl;
}

class Time
{
    private:
        int hour,minute,second;
        static int count;
    public:
        Time(int h=0,int m=0,int s=0):hour(h),minute(m),second(s)
        {
            count++;
            std::cout<<"Constructor of Time with 1~3 parameter."<<std::endl;
        }
        Time(const Time& t);
        ~Time(){std::cout<<"Destructor of Date: "<<hour<<'-'<<minute<<'-'<<second<<std::endl;}
        friend void DateTime(const Date& d,const Time& t);

};
int Time::count = 0;
Time::Time(const Time& t)
{
    hour = t.hour;
    minute = t.minute;
    second = t.second;
    std::cout<<"Copy Constructor of Date."<<std::endl;
}
void DateTime(const Date& d,const Time& t)
{
    std::cout<<"Now is "<<d.year<<'-'<<d.month<<'-'<<d.day<<' '
        <<t.hour<<'-'<<t.minute<<'-'<<t.second<<std::endl;
}

class Test
{
    int X,Y;
    public :
        Test():X(0),Y(0){}
        Test(int x);
        Test(int x,int y);
        ~Test(){}
        int Add(int x,int y);
        int Add(int x);
        int Add();                      //----这三个为函数重载----
        int Print(){std::cout<<"X="<<X<<",Y="<<Y<<std::endl;}
};
int Test::Add()
{
    return X+Y;
}
int Test::Add(int x)
{
    X=Y=x;
    return X+Y;
}
int Test::Add(int x,int y)
{
    X = x;
    Y = y;
    return X+Y;
}
Test::Test(int x,int y):X(x),Y(y)
{
    std::cout<<"Constructor of Test with 2 paremeter."<<std::endl;
}
Test::Test(int x):X(x)
{
    Y = x*x;
    std::cout<<"Constructor of Test with 1 paremeter."<<std::endl;
}



