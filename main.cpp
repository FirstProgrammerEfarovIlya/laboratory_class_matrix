#include <iostream>
#include <cmath>
#include "matrix.h"

using namespace std;
using namespace algebra;



int main()
{
    Matrix matr1(5, 5);
    matr1.randint(1, 10);
    matr1.print_matrix(3, 0);
    matr1.delta(down);
    matr1.print_matrix(3, 0);
//    FuncFillMatrix lambda1 = [](double x, unsigned i, unsigned j)->double{return pow(x, i*2 + j*2);};
//    matr1.fill_matrix(lambda1);
//    matr1.print_matrix(13, 0);
    return 0;
}
