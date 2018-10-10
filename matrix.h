#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
using namespace std;

using vectord = vector<double>;
using matrixd = vector<vector<double>>;
using FuncFillMatrix = double(*)(double, unsigned, unsigned);

namespace algebra
{
    enum Error {SizeError, ZeroDivision};
    enum Direction {right, left, up, down};

    class Matrix
    {
    private:
        matrixd content;
    public:
        Matrix(unsigned m = 0, unsigned n = 0);
        double element(unsigned i, unsigned j) const;
        void set_element(double e, unsigned i, unsigned j);
        vectord row(unsigned i) const;
        void set_row(vectord &v, unsigned i);
        void print_element(unsigned i, unsigned j, int a = 7, int b = 2) const;
        void print_row(unsigned i, int a = 7, int b = 2) const;
        void print_matrix(int a = 7, int b = 2) const;
        void input_matrix();
        Matrix operator + (const Matrix &matr) const;
        Matrix operator - (const Matrix &matr) const;
        void clear();
        void resize(unsigned m, unsigned n);
        void randint(int a = 0, int b = 100);
        void random();
        void randfloat(int a = 0, int b = 100);
        void same_num(double num);
        void one();
        void zero();
        Matrix operator * (const Matrix &matr) const;
        Matrix operator * (double num) const;
        Matrix T() const;
        Matrix minor(unsigned i, unsigned j) const;
        double det() const;
        Matrix inverse() const;
        unsigned size_W() const;
        unsigned size_H() const;
        void operator *= (const Matrix &matr);
        void operator += (const Matrix &matr);
        void operator -= (const Matrix &matr);
        void operator *= (double num);
        void fill_matrix(FuncFillMatrix func);
        Matrix replace_line(unsigned index) const;
        Matrix method_gauss() const;
        void delta(Direction d);
        vectord reverse_step();
        friend Matrix operator * (double num, Matrix &matr);
    };
}

#endif // MATRIX_H
