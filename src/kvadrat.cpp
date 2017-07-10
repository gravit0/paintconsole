#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>
#include "kvadrat.hpp"
namespace Kvadrat {
const char null_char = ' ';
const char hline_char = '-';
const char vline_char = '|';

typedef char matrix_type;
matrix_type* matrix;
int mPosX=0,mPosY=0; //Размеры матрицы
double zPosX=0,zPosY=0; //Выбранная позиция
int size_kvadrat = 2;
bool setPixel(double x,double y,matrix_type t)
{
    if(zPosX > x || ( zPosX + mPosX) < x) return false;
    if(zPosY > y || ( zPosY + mPosY) < y) return false;
    int real_matrix_index = round((y-zPosY)*mPosX)+round(x-zPosX);
    matrix[real_matrix_index] = t;
    return true;
}
void renderKvadrat(int x,int y,int size)
{
    for(int i=x;i<(x+size);i++)
    {
        setPixel(i+zPosX,y+zPosY,hline_char);
    }
    for(int i=y;i<(y+size);i++)
    {
        setPixel(x+zPosX,i+zPosY,vline_char);
    }
    for(int i=y;i<(y+size);i++)
    {
        setPixel(x+zPosX+size,i+zPosY,vline_char);
    }
    for(int i=x;i<(x+size);i++)
    {
        setPixel(i+zPosX,y+zPosY+size,hline_char);
    }
}
int run(int argc,char** argv)
{
    
    //Создание
    try {
    std::cout << "Размер матрицы(x y): ";
    std::cin >> mPosX >> mPosY;
    std::cout << "Текущая позиция(x y): ";
    std::cin >> zPosX >> zPosY;
    std::cout << "Размер квадрата: ";
    std::cin >> size_kvadrat;
    matrix = new matrix_type[(mPosX+1)*(mPosY+1)];
    }
    catch(std::exception e)
    {
        std::cout << e.what();
        return 1;
    }
    //Заполнение
    for(int i=0;i<mPosY;i++)
    for(int j=0;j<mPosX;j++)
    {
        matrix[i*mPosX+j] = null_char;
    }
    //Рисуем
    
    //Первая точка
    int fristX=0,fristY=0; 
    fristX=( (int)round(zPosX) ) % size_kvadrat;//Смещение по X
    fristY=( (int)round(zPosY) ) % size_kvadrat;//Смещение по Y
    for(int i=0;i<mPosX+size_kvadrat+1;i=i+size_kvadrat)
    {
        for(int j=0;j<mPosY+size_kvadrat+1;j=j+size_kvadrat)
        renderKvadrat(i-fristX,j-fristY,size_kvadrat);
    }
    //Вывод
    for(int i=0;i<mPosY;i++) {
    for(int j=0;j<mPosX;j++)
    {
        std::cout << matrix[i*mPosX+j];
    }
    std::cout << std::endl;
    }
    delete[] matrix;
    return 0;
}
}
