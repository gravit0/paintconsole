#include <iostream>
#include <vector>
typedef unsigned char matrix_type;
class MyMatrix
{
public:
    matrix_type* mat;
    int posX=0,posY=0;
    MyMatrix()
    {

    }
    MyMatrix(int x,int y)
    {
        mat = new matrix_type[x*y];
        posX=x;
        posY=y;
    }
    MyMatrix(int x,int y,matrix_type* matr)
    {
        mat = matr;
        posX=x;
        posY=y;
    }
    bool set(int x,int y,matrix_type c)
    {
        if(x<0 || x>posX) return false;
        if(y<0 || y>posY) return false;
        mat[y*posX+x] = c;
    }
    bool get(int x,int y)
    {
        if(x<0 || x>posX) return false;
        if(y<0 || y>posY) return false;
        return mat[y*posX+x];
    }
    bool swapData(int x,int y,int x2,int y2)
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
    matrix_type* operator [](int y)
    {
        return &(mat[y*posX]);
    }
    void print()
    {
        for(int i=0;i<posX;i++) {
            for(int j=0;j<posY;j++)
            {
                std::cout << mat[i*posX+j];
            }
            std::cout << std::endl;
        }
    }
    void fill(matrix_type c)
    {
        for(int i=0;i<posX;i++) {
            for(int j=0;j<posY;j++)
            {
                mat[i*posX+j] = c;
            }
        }
    }
    virtual ~MyMatrix()
    {
        //delete[] mat;
    }
};
class Sudoku : public MyMatrix {
public:
    Sudoku(int x,int y)
    {
        mat = new matrix_type[x*y];
        posX=x;
        posY=y;
    }
    Sudoku(int x,int y,matrix_type* matr)
    {
        mat = matr;
        posX=x;
        posY=y;
    }
    virtual ~Sudoku()
    {
        
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
int main(int argc,char** argv)
{
    std::ios::sync_with_stdio(false);
    matrix_type stdmatr[] ={
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
        Sudoku matrix(posX,posY,stdmatr);
        matrix.print();
        std::cout << std::endl;
        matrix.swapStolb(0,0,1);
        matrix.print();
    }
    catch(std::exception e)
    {
        std::cout << e.what();
        return 1;
    }
    
    return 0;
}
