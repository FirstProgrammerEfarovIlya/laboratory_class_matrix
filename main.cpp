#include <iostream>
#include "matrix.h"

using namespace std;
using namespace algebra;
int main()
{
    Matrix matr1(3, 3);
    matr1.input_matrix();
    matr1.print_matrix(7, 2);
    return 0;
}
