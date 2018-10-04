#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
using namespace std;

using vectord = vector<double>;
using matrixd = vector<vector<double>>;

namespace algebra
{
    class Matrix
    {
    private:

    public:
        matrixd content;
        Matrix(unsigned m, unsigned n);
    };
}

#endif // MATRIX_H
