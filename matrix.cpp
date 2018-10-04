#include "matrix.h"
#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;

namespace algebra
{
    Matrix::Matrix(unsigned m, unsigned n)
    {
        // инициализация матрицы
        for (unsigned i = 0; i < m; i++)
        {
            vectord line(n);
            this->content.push_back(line);
        }
    }


    double Matrix::get_element(unsigned i, unsigned j)
    {
        return this->content[i][j];
    }


    void Matrix::set_element(double e, unsigned i, unsigned j)
    {
        this->content[i][j] = e;
    }


    vectord Matrix::get_row(unsigned i)
    {
        return this->content[i];
    }


    void Matrix::set_row(vectord &v, unsigned i)
    {
        this->content[i] = v;
    }


    void Matrix::print_element(unsigned i, unsigned j, int a, int b)
    {
        cout << fixed << setw(a) << setprecision(b) << "element[" << i << "]"
             << "[" << j << "] = " << content[i][j] << endl;
    }


    void Matrix::input_element(unsigned i, unsigned j)
    {
         cout << "element[" << i << "]" << "[" << j << "] = ";
         cin >> this->content[i][j];
    }


    void Matrix::print_row(unsigned i, int a, int b)
    {
        cout << "{";
        for (double e : this->content[i])
        {
            cout << fixed << setw(a) << setprecision(b) << e << ";";
        }
        cout << "}";
    }


    void Matrix::input_row(unsigned i)
    {
        cout << "Enter " << i << "-row : " << endl;
        cout << ": ";
        for (double &e : this->content[i])
        {
            cin >> e;
        }
    }


    void Matrix::print_matrix(int a, int b)
    {
        cout << endl;

        for (vectord line : this->content)
        {
            for (double e : line)
            {
                cout << fixed << setw(a) << setprecision(b) << e;
            }
            cout << endl;
        }

        cout << endl;
    }


    void Matrix::input_matrix()
    {
        cout << endl;
        cout << "Enter matrix" << endl;
        for (vectord &line : this->content)
        {
            cout << ": ";
            for (double &e : line)
            {
                cin >> e;
            }
        }
        cout << endl;
    }
}
