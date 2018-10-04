#include <iostream>
#include "matrix.h"

using namespace std;
using namespace algebra;
int main()
{
    Matrix matr1(3, 3);
    cout << matr1.get_size() << endl;
    matr1.set_size(2, 2);
    cout << matr1.get_size() << endl;
    matr1.print_matrix();
    return 0;
}
