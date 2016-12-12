#include"Matrix.h"
#include<iomanip>
#include<cmath>
#include<cstdlib>
Matrix::Matrix(int r=1,int c=1):row(r),col(c)
{
    marray=new double*[row];
    marray[0]=new double[row*col]();
    for(int i=0;i<row;i++)
        marray[i]=marray[0]+i*col;
}
Matrix::~Matrix()
{
    delete []marray[0];
    delete []marray;
    marray=NULL;
}
Matrix::Matrix(const Matrix &m)
{
    row=m.row;
    col=m.col;
    marray=new double*[row];
    marray[0]=new double[row*col]();
    for(int i=0;i<row;i++)
    {
        marray[i]=marray[0]+i*col;
        for(int j=0;j<col;j++)
            (*this)(i,j)=m(i,j);
    }
}
Matrix& Matrix::operator=(const Matrix &m)
{
    if(this->row!=m.row||this->col!=m.col)
        exit(1);
    if(this!=&m)
    {
        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++)
                (*this)(i,j)=m(i,j);
    }
    return *this;
}
double& Matrix::operator()(int i,int j)
{
    static double d;
    d=0;
    if(i>=0&&j>=0&&i<row&&j<col)
        return marray[i][j];
    return d;
}
const double& Matrix::operator()(int i,int j)const
{
    static double d;
    d=0;
    if(i>=0&&j>=0&&i<row&&j<col)
        return marray[i][j];
    return d;
}
std::ostream &operator<<(std::ostream &os,const Matrix &m)///////////////////
{
    for(int i=0;i<m.row;i++)
    {
        for(int j=0;j<m.col;j++)
        {
            os<<std::setprecision(4)<<std::setw(8)<<std::setiosflags(std::ios::fixed|std::ios::right)<<m.marray[i][j];
        }
        os<<std::endl;
    }
    return os;
}
std::istream &operator>>(std::istream &is,Matrix &m)
{
    for(int i=0;i<m.row;i++)
        for(int j=0;j<m.col;j++)
            is>>m.marray[i][j];
    return is;
}
Matrix operator+(const Matrix &m1,const Matrix &m2)
{
    if(m1.row!=m2.row||m1.col!=m2.col)
        exit(2);
    Matrix temp(m1.row,m1.col);
    for(int i=0;i<m1.row;i++)
        for(int j=0;j<m1.col;j++)
            temp(i,j)=m1(i,j)+m2(i,j);
    return temp;
}
Matrix operator-(const Matrix &m1,const Matrix &m2)
{
    if(m1.row!=m2.row||m1.col!=m2.col)
        exit(2);
    Matrix temp(m1.row,m1.col);
    for(int i=0;i<m1.row;i++)
        for(int j=0;j<m1.col;j++)
            temp(i,j)=m1(i,j)-m2(i,j);
    return temp;
}
Matrix operator*(const Matrix &m1,const Matrix &m2)
{
    if(m1.col!=m2.row)
        exit(3);
    Matrix temp(m1.row,m2.col);
    for(int i=0;i<m1.row;i++)
        for(int j=0;j<m2.col;j++)
            for(int t=0;t<m1.col;t++)
                temp(i,j)+=m1(i,t)*m2(t,j);
    return temp;
}
Matrix transposition(const Matrix &m)
{
    Matrix temp(m.col,m.row);
    for(int i=0;i<m.row;i++)
        for(int j=0;j<m.col;j++)
            temp(j,i)=m(i,j);
    return temp;
}
Matrix inverse(Matrix &m)
{
    if(m.col!=m.row)
        exit(255);
    int *z=new int[m.row];
    for(int i=0;i<m.row;i++)
        *(z+i)=i;
    for(int k=0;k<m.col;k++)
    {
        double dflag=0;
        int l=0;
        for(int t=k;t<m.row;t++)
            if(fabs(m(t,k))>dflag)
            {dflag=fabs(m(t,k));l=t;}
        *(z+k)=l;
        if(0==dflag)
        {delete []z;exit(255);}
        if(l!=k)
            for(int j=0;j<m.col;j++)
                swap(m(k,j),m(l,j));
        double c=1/m(k,k);
        m(k,k)=c;
        for(int j=0;j<m.col;j++)
        {
            if(j==k){continue;}
            m(k,j)=c*m(k,j);
        }
        for(t=0;t<m.row;t++)
        {
            if(t==k){continue;}
            for(int j=0;j<m.col;j++)
            {
                if(j==k){continue;}
                m(t,j)=m(t,j)-m(t,k)*m(k,j);
            }
        }
        for(t=0;t<m.row;t++)
        {
            if(t==k){continue;}
            m(t,k)=-c*m(t,k);
        }
    }
    for(k=m.row-1;k>=0;k--)
    {
        int q=*(z+k);
        if(q!=k)
            for(int t=0;t<m.row;t++)
                swap(m(t,q),m(t,k));
    }

    delete []z;
    return m;
}
