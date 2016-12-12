#include<iostream>

class Point
{
    public:
        Point(int a=0,int b=0):X(a),Y(b) {}
        Point(const Point& p);
        void InitPoint(int a,int b);
        void Move(int xoff,int yoff);
        int GetX(){return X;}
        int GetY(){return Y;}
    private:
        int X,Y;
};
Point::Point(const Point& p)
{
    X = p.X;
    Y = p.Y;
}
inline void Point::InitPoint(int a, int b)
{
    X = a;
    Y = b;
}
inline void Point::Move(int xoff,int yoff)
{
    X += xoff;
    Y += yoff;
}

class Rectangle : public Point
{
    public:
        Rectangle(int x=0,int y=0,int w=1,int h=1):Point(x,y),W(w),H(h) {}
        Rectangle(const Rectangle& r);
        void InitRec(int x=0,int y=0,int w=1,int h=1);
        void ShowRec();
        int GetW() {return W;}
        int GetH() {return H;}
    private:
        int W,H;
};
Rectangle::Rectangle(const Rectangle& r):Point(r)       //--Rectangle是Point的子类型--
{
    W = r.W;
    H = r.H;
}
void Rectangle::InitRec(int x,int y,int w,int h)
{
    InitPoint(x,y);
    W = w;
    H = h;
}
void Rectangle::ShowRec()
{
    std::cout<<GetX()<<'\t'<<GetY()<<'\t'<<W<<'\t'<<H<<std::endl;
}
