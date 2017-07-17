#include <iostream>
#include <vector>
#include "mymatrix.hpp"
#include "sudoku.hpp"
namespace Sudoku {
class SudokuMatrix : public MyMatrix {
public:
    SudokuMatrix(int x,int y)
    {
        mat = new matrix_type[x*y];
        posX=x;
        posY=y;
    }
    SudokuMatrix(int x,int y,matrix_type* matr)
    {
        mat = matr;
        posX=x;
        posY=y;
    }
    void swapLine(int block,int line1,int line2)
    {
        int j1 = block*3 + line1;
        int j2 = block*3 + line2;
        for(int i=0;i<posX;i++) {
            //mat[i*posX+j1] = c;
            swapData(i,j1,i,j2);
        }
    }
    void swapStolb(int block,int st1,int st2)
    {
        int j1 = block*3 + st1;
        int j2 = block*3 + st2;
        for(int i=0;i<posY;i++) {
            //mat[i*posX+j1] = c;
            swapData(j1,i,j2,i);
        }
    }
};
int run(int argc,char** argv)
{
    std::ios::sync_with_stdio(false);
    MyMatrix::matrix_type stdmatr[] ={
    '1','2','3','4','5','6','7','8','9',
    '4','5','6','7','8','9','1','2','3',
    '7','8','9','1','2','3','4','5','6',
    '2','3','4','5','6','7','8','9','1',
    '5','6','7','8','9','1','2','3','4',
    '8','9','1','2','3','4','5','6','7',
    '3','4','5','6','7','8','9','1','2',
    '6','7','8','9','1','2','3','4','5',
    '9','1','2','3','4','5','6','7','8'
    };
    int posX=9,posY=9;
    try {
        SudokuMatrix matrix(posX,posY,stdmatr);
        matrix.print();
        std::cout << std::endl;
		srand(time(0));
		auto lam_stolb = [&]() {
			int rand_1 = rand() % 3;
			int rand_2 = rand() % 3;
			int rand_3 = rand() % 2;
			int pos = 0;
			if(rand_2 == 0 && rand_3 == 0) pos = 1;
			else if(rand_2 == 0 && rand_3 == 1) pos = 2;
			if(rand_2 == 1 && rand_3 == 0) pos = 0;
			if(rand_2 == 1 && rand_3 == 1) pos = 2;
			if(rand_2 == 2 && rand_3 == 0) pos = 0;
			if(rand_2 == 2 && rand_3 == 1) pos = 1;
			//std::cout << rand_1 << std::endl;
			matrix.swapStolb(rand_1,rand_2,pos);
		};
		auto lam_line = [&]() {
			int rand_1 = rand() % 3;
			int rand_2 = rand() % 3;
			int rand_3 = rand() % 2;
			int pos = 0;
			if(rand_2 == 0 && rand_3 == 0) pos = 1;
			else if(rand_2 == 0 && rand_3 == 1) pos = 2;
			else if(rand_2 == 1 && rand_3 == 0) pos = 0;
			else if(rand_2 == 1 && rand_3 == 1) pos = 2;
			else if(rand_2 == 2 && rand_3 == 0) pos = 0;
			else if(rand_2 == 2 && rand_3 == 1) pos = 1;
			//std::cout << rand_1 << std::endl;
			matrix.swapLine(rand_1,rand_2,pos);
		};
		for(int i=0;i<128;i++) {
			int rand_4 = rand() % 2;
			if(rand_4 == 0) lam_stolb();
			else lam_line();
		}
        matrix.print();
		std::cout << std::endl;
		for(int i=0;i<32;i++) {
			int rand_1 = rand() % 81;
			//std::cout << rand_1 << std::endl;
			matrix.mat[rand_1] = ' ';
		}
        matrix.print();
    }
    catch(std::exception e)
    {
        std::cout << e.what();
        return 1;
    }
    
    return 0;
}
};
