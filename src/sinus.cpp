#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>
#include "sinus.hpp"
namespace Sinus {
double X_EXPANDING = 4.0;
int posX=0,posY=0;
int func(double arg)
{
    double sinArg =  ((double)arg / (double)(posX)) * (M_PI * 2.0) * X_EXPANDING;
    double tmp = (cos(sinArg) + 1.0) / 2.0;
    double tmp2 = (1 - tmp)*((double)posY -1);
    return round(tmp2);
}
typedef unsigned char matrix_type;
matrix_type* matrix;
void drawLine(int x1,int y1,int x2,int y2,char t)
{
    int side1 = x1-x2;
    int side2 = y1-y2;
    
    if(side2 == 0)
    {
        for(int i=x1;i>=x2;i--) matrix[y1*posX+i] = t;
        return;
    }
    if(side1 == 0)
    {
        for(int i=y1;i>y2;i--) matrix[i*posX+x1] = t;
        return;
    }
    double tgA = (double)side1 /(double)side2;
    for(int i=x1;i>x2;i--)
    {
        
        int a = y1+round(((double)i / tgA ) * posY);
        std::cout << tgA << ' ' << i << ' ';
        matrix[a*posX+i] = t;
    }
}
int run(int argc,char** argv)
{
    std::cout << "Размер матрицы: ";
    std::cin >> posX >> posY;
    std::cout << "Число проходов: ";
    std::cin >> X_EXPANDING;
    //Создание матрицы
    matrix = new matrix_type[(posX+1)*(posY+1)];
    //Заполнение
    for(int i=0;i<posY;i++)
    for(int j=0;j<posX;j++)
    {
        matrix[i*posX+j] = ' ';
    }
    //Построение
    drawLine(posX,posY/2,0,posY/2 ,'-');
    drawLine(posX/2,posY,posX/2,0 ,'|');
    for(int i=0;i<posX;i++)
    {
        matrix[func(i)*posX+i] = 'x';
        //std::cout << tmp << "/" << tmp2 << " ";
    }
    std::cout << "\n";
    //Вывод
    for(int i=0;i<posY;i++) {
    for(int j=0;j<posX;j++)
    {
        std::cout << matrix[i*posX+j];
    }
    std::cout << "\n";
    }
    delete[] matrix;
    return 0;
}
}
