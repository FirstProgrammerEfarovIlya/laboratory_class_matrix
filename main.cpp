#include <iostream>
#include "matrix.h"

using namespace std;
using namespace algebra;
int main()
{
    Matrix matr1(3, 2), matr3;
    matr1.randint();
    matr1.print_matrix(3, 0);
    matr3 = matr1 * 10;
    matr3.print_matrix(5, 0);
    return 0;
}
