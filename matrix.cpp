#include "matrix.h"
#include <vector>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

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


    Matrix Matrix::operator + (Matrix &matr)
    {
        // сложение матриц
        unsigned m1 = this->content.size();
        unsigned n1 = this->content[0].size();
        unsigned m2 = matr.content.size();
        unsigned n2 = matr.content[0].size();
        try
        {
            if (m1 != m2 || n1 != n2)
            {
                throw 0;
            }
        }
        catch(int x)
        {
            cout << endl;
            cout << "Matrices have different sizes!!!" << endl;
            exit(x);
        }

        Matrix rezult(m1, n1);

        for (unsigned i = 0; i < m1; i++)
        {
            for (unsigned j = 0; j < n1; j++)
            {
                rezult.content[i][j] = this->content[i][j] + matr.content[i][j];
            }
        }

        return rezult;
    }


    Matrix Matrix::operator - (Matrix &matr)
    {
        // вычитание матриц
        unsigned m1 = this->content.size();
        unsigned n1 = this->content[0].size();
        unsigned m2 = matr.content.size();
        unsigned n2 = matr.content[0].size();
        try
        {
            if (m1 != m2 || n1 != n2)
            {
                throw 0;
            }
        }
        catch(int x)
        {
            cout << endl;
            cout << "Matrices have different sizes!!!" << endl;
            exit(x);
        }

        Matrix rezult(m1, n1);

        for (unsigned i = 0; i < m1; i++)
        {
            for (unsigned j = 0; j < n1; j++)
            {
                rezult.content[i][j] = this->content[i][j] - matr.content[i][j];
            }
        }

        return rezult;
    }


    unsigned Matrix::get_size()
    {
        unsigned s = 0;
        for (vectord line : this -> content)
        {
            s += line.size();
        }
        return s;
    }


   void Matrix::clear()
   {
       content.clear();
   }


   void Matrix::set_size(unsigned m, unsigned n)
   {
       matrixd cmatr(m);
       unsigned mc = content.size();
       unsigned nc = content[0].size();
       for (unsigned i = 0; i < m; i++)
       {
           vectord line(n);
           for (unsigned j = 0; j < n; j++)
           {
               if (i >= mc || j >= nc)
               {
                   line[j] = 0;
               }
               else
               {
                   line[j] = content[i][j];
               }
           }
           cmatr[i] = line;
       }
       content = cmatr;
   }


   void Matrix::random(int a, int b)
   {
       for (vectord &line : content)
       {
           for (double &e : line)
           {
               e = rand() % b + a;
           }
       }
   }


   void same_num(double num);
   void one();
   void zero();
}
