#include <iostream>
#include "matrix.h"

using namespace std;
using namespace algebra;
int main()
{
    Matrix matr1(10, 10);
    matr1.set_element(11.0, 1, 1);
    cout << matr1.get_element(1, 1) << endl;
    return 0;
}
