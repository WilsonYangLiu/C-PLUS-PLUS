#ifndef __MATRIX_H__
    #define __MATRIX_H__
    //#include "RowVector.cpp"
class Matrix
{
    double **marray;
    int row,col;
public:
    Matrix(int,int);
    ~Matrix();
    Matrix(const Matrix&);
    Matrix& operator=(const Matrix&);
    double& operator()(int,int);
    const double& operator()(int,int)const;
    friend std::ostream &operator<<(std::ostream&,const Matrix&);
    friend std::istream &operator>>(std::istream&,Matrix&);
    friend Matrix operator+(const Matrix&,const Matrix&);
    friend Matrix operator-(const Matrix&,const Matrix&);
    friend Matrix operator*(const Matrix&,const Matrix&);
    friend Matrix transposition(const Matrix&);
    friend Matrix inverse(Matrix&);
    friend Matrix inv(const Matrix&);
};
#endif // __MATRIX_H__
inline void swap(double& a,double& b)
{
    double t=a;
    a=b;b=t;
}
