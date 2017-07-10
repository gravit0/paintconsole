#include "mymatrix.hpp"
#include <iostream>
MyMatrix::MyMatrix()
    {

    }
    MyMatrix::MyMatrix(int x,int y)
    {
        mat = new matrix_type[x*y];
        posX=x;
        posY=y;
    }
    MyMatrix::MyMatrix(int x,int y,MyMatrix::matrix_type* matr)
    {
        mat = matr;
        posX=x;
        posY=y;
    }
    bool MyMatrix::set(int x,int y,MyMatrix::matrix_type c)
    {
        if(x<0 || x>posX) return false;
        if(y<0 || y>posY) return false;
        mat[y*posX+x] = c;
    }
    bool MyMatrix::get(int x,int y)
    {
        if(x<0 || x>posX) return false;
        if(y<0 || y>posY) return false;
        return mat[y*posX+x];
    }
    bool MyMatrix::swapData(int x,int y,int x2,int y2)
    {
        if(x<0 || x>posX) return false;
        if(y<0 || y>posY) return false;
        if(x2<0 || x2>posX) return false;
        if(y2<0 || y2>posY) return false;
        int pos1 = y*posX+x;
        int pos2 = y2*posX+x2;
        matrix_type z = mat[pos1];
        mat[pos1] = mat[pos2];
        mat[pos2] = z;
        return true;
    }
    MyMatrix::matrix_type* MyMatrix::operator [](int y)
    {
        return &(mat[y*posX]);
    }
    void MyMatrix::print()
    {
        for(int i=0;i<posX;i++) {
            for(int j=0;j<posY;j++)
            {
                std::cout << mat[i*posX+j];
            }
            std::cout << std::endl;
        }
    }
    void MyMatrix::fill(MyMatrix::matrix_type c)
    {
        for(int i=0;i<posX;i++) {
            for(int j=0;j<posY;j++)
            {
                mat[i*posX+j] = c;
            }
        }
    }
    MyMatrix::~MyMatrix()
    {
        //delete[] mat;
    }
