#include <iostream>
#include "matrix.h"

using namespace std;
using namespace algebra;



int main()
{
    Matrix matr1(3, 3), matr2(3, 3), matr3(3, 3);
    matr1.randint(1, 10);
    matr1.print_matrix(3, 0);
    matr2.randint(1, 10);
    matr2.print_matrix(3, 0);
    matr3.randint(1, 10);
    matr3.print_matrix(3, 0);
    matr2 = matr2 + matr1 + matr3;
    matr2.print_matrix(3, 0);
    return 0;
}
