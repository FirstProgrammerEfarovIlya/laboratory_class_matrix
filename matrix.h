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
        Matrix(unsigned m = 0, unsigned n = 0);
        double element(unsigned i, unsigned j);
        void set_element(double e, unsigned i, unsigned j);
        vectord row(unsigned i);
        void set_row(vectord &v, unsigned i);
        void print_element(unsigned i, unsigned j, int a = 7, int b = 2);
        void print_row(unsigned i, int a = 7, int b = 2);
        void print_matrix(int a = 7, int b = 2);
        void input_matrix();
        Matrix operator + (Matrix &matr);
        Matrix operator - (Matrix &matr);
        unsigned size();
        void clear();
        void resize(unsigned m, unsigned n);
        void randint(int a = 0, int b = 100);
        void random();
        void randfloat(int a = 0, int b = 100);
        void same_num(double num);
        void one();
        void zero();
        Matrix operator * (Matrix &matr);
        Matrix operator * (double num);
        void T();
        Matrix minor(unsigned i, unsigned j);
        double det();
        void inverse();
        friend Matrix operator * (double num, Matrix &matr);
    };
}

#endif // MATRIX_H
