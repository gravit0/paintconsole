#include <iostream>
#include <string>
#include "sudoku.hpp"
#include "kvadrat.hpp"
#include "sinus.hpp"
int main(int argc,char** argv)
{
    if(argc < 2)
    {
        std::cout << "sudoku, kvadrat, sinus\n";
        return 0;
    }
    else
    {
        std::string cmd(argv[1]);
        if(cmd == "sudoku") return Sudoku::run(argc,argv);
        else if(cmd == "kvadrat") return Kvadrat::run(argc,argv);
        else if(cmd == "sinus") return Sinus::run(argc,argv);
        else std::cout << "Unknown command: " << cmd << std::endl;
    }
}
