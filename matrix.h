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
        matrixd content;
    public:
        Matrix(unsigned m, unsigned n);
        double get_element(unsigned i, unsigned j);
        void set_element(double e, unsigned i, unsigned j);
    };
}

#endif // MATRIX_H
