#include <iostream>
#include "matrix.h"

using namespace std;
using namespace algebra;
int main()
{
    Matrix matr1(10, 10);
    cout << matr1.content[0][0] << endl;
    return 0;
}
