#include <iostream>
#include <cmath>
#include "matrix.h"

using namespace std;
using namespace algebra;



int main()
{
    Matrix matr1(3, 4);
    vectord x;
    input_matrix(matr1);
    print_matrix(matr1, 3, 0);
    FuncFillMatrix lambda1 = [](double x, unsigned i, unsigned j)->double{return pow(x, i*2 + j*2);};
    matr1.fill_matrix(lambda1);
//    matr1 = method_gauss(matr1);
//    x = reverse_step(matr1);
    print_matrix(matr1, 13, 8);
//    for (unsigned i = 0; i < x.size(); i++)
//    {
//        cout << "x" << i + 1 << " = " << x[i] << "; ";
//    }
//    cout << endl;
    return 0;
}
