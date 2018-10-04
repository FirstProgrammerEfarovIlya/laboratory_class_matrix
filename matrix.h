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
        Matrix(unsigned m = 1, unsigned n = 1);
        double get_element(unsigned i, unsigned j);
        void set_element(double e, unsigned i, unsigned j);
        vectord get_row(unsigned i);
        void set_row(vectord &v, unsigned i);
        void print_element(unsigned i, unsigned j, int a = 7, int b = 2);
        void input_element(unsigned i, unsigned j);
        void print_row(unsigned i, int a = 7, int b = 2);
        void input_row(unsigned i);
        void print_matrix(int a = 7, int b = 2);
        void input_matrix();
        Matrix operator + (Matrix &matr);
        Matrix operator - (Matrix &matr);
        unsigned get_size();
        void clear();
        void set_size(unsigned m, unsigned n);
        void randint(int a = 0, int b = 100);
        void random();
        void randfloat(int a = 0, int b = 100);
        void same_num(double num);
        void one();
        void zero();
        Matrix operator * (Matrix &matr);
        Matrix operator * (double num);
    };
}

#endif // MATRIX_H
