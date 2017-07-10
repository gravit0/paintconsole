class MyMatrix
{
public:
    typedef unsigned char matrix_type;
    matrix_type* mat;
    int posX=0,posY=0;
    MyMatrix();
    MyMatrix(int x,int y);
    MyMatrix(int x,int y,matrix_type* matr);
    bool set(int x,int y,matrix_type c);
    bool get(int x,int y);
    bool swapData(int x,int y,int x2,int y2);
    matrix_type* operator [](int y);
    void print();
    void fill(matrix_type c);
    virtual ~MyMatrix();
};
