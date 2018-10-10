#include "matrix.h"
#include <vector>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <cmath>

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


    double Matrix::element(unsigned i, unsigned j) const
    {
        return this->content[i][j];
    }


    void Matrix::set_element(double e, unsigned i, unsigned j)
    {
        this->content[i][j] = e;
    }


    vectord Matrix::row(unsigned i) const
    {
        return this->content[i];
    }


    void Matrix::set_row(vectord &v, unsigned i)
    {
        if (v.size() == content[0].size())
        {
            this->content[i] = v;
        }
        else
        {
            throw SizeError;
            /*
            "The number of elements of the getting row is"
            " ​​not equal to the number of elements of the setting row!!!"
                       */
        }
    }


    void Matrix::print_element(unsigned i, unsigned j, int a, int b) const
    {
        cout << fixed << setw(a) << setprecision(b) << "element[" << i << "]"
             << "[" << j << "] = " << content[i][j] << endl;
    }


    void Matrix::print_row(unsigned i, int a, int b) const
    {
        cout << "{";
        for (double e : this->content[i])
        {
            cout << fixed << setw(a) << setprecision(b) << e << ";";
        }
        cout << "}";
    }


    void Matrix::print_matrix(int a, int b) const
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


    Matrix Matrix::operator + (const Matrix &matr) const
    {
        // сложение матриц
        unsigned m1 = this->content.size();
        unsigned n1 = this->content[0].size();
        unsigned m2 = matr.content.size();
        unsigned n2 = matr.content[0].size();

        if (m1 != m2 || n1 != n2)
        {
            throw SizeError;
            //  Matrices have different sizes!!!
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


    Matrix Matrix::operator - (const Matrix &matr) const
    {
        // вычитание матриц
        unsigned m1 = this->content.size();
        unsigned n1 = this->content[0].size();
        unsigned m2 = matr.content.size();
        unsigned n2 = matr.content[0].size();

        if (m1 != m2 || n1 != n2)
        {
            throw SizeError;
            //  Matrices have different sizes!!!
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


   void Matrix::clear()
   {
       content.clear();
   }


   void Matrix::resize(unsigned m, unsigned n)
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


   void Matrix::randint(int a, int b)
   {
       srand(time(0));
       for (vectord &line : content)
       {
           for (double &e : line)
           {
               e = double(rand() % b + a);
           }
       }
   }


   void Matrix::random()
   {
       srand(time(0));
       for (vectord &line : content)
       {
           for (double &e : line)
           {
               e = rand()/double(RAND_MAX);
           }
       }
   }


   void Matrix::randfloat(int a, int b)
   {
       srand(time(0));
       for (vectord &line : content)
       {
           for (double &e : line)
           {
               e = double(rand() % b + a) + rand()/double(RAND_MAX);
           }
       }
   }


   void Matrix::same_num(double num)
   {
       for (vectord &line : content)
       {
           for (double &e : line)
           {
               e = num;
           }
       }
   }



   void Matrix::one()
   {
       unsigned m = content.size();
       unsigned n = content[0].size();
       for (unsigned i = 0; i < m; i++)
       {
           for (unsigned j = 0; j < n; j++)
           {
               if (i == j)
               {
                   content[i][j] = 1.0;
               }
               else
               {
                   content[i][j] = 0.0;
               }
           }
       }
   }



   void Matrix::zero()
   {
       unsigned m = content.size();
       unsigned n = content[0].size();
       matrixd matr(m);
       vectord line(n);
       for (unsigned i = 0; i < m; i++)
       {
           matr[i] = line;
       }
       content = matr;
   }


   Matrix Matrix::operator * (const Matrix &matr) const
   {
       // умножение матриц
       unsigned m1 = this->content.size();
       unsigned n1 = this->content[0].size();
       unsigned m2 = matr.content.size();
       unsigned n2 = matr.content[0].size();
       Matrix rezult(m1, n2);

       if (n1 != m2)
       {
           throw SizeError;
           /*  "The number of columns of the first matrix is"
            " ​​not equal to the number of rows of the second matrix!!!"*/
       }


       for (unsigned i = 0; i < m1; i++)
       {
           for (unsigned j = 0; j < n2; j++)
           {
               for (unsigned k = 0; k < n1; k++)
               {
                   rezult.content[i][j] += this->content[i][k] * matr.content[k][j];
               }
           }
       }

       return rezult;
   }


   Matrix Matrix::operator * (double num) const
   {
       // умножение матрицы на скаляр
       unsigned m = this->content.size();
       unsigned n = this->content[0].size();
       Matrix rezult(m, n);
       for (unsigned i = 0; i < m; i++)
       {
           for (unsigned j = 0; j < n; j++)
           {
               rezult.content[i][j] = this->content[i][j] * num;
           }
       }
       return rezult;
   }


   Matrix Matrix::T() const
   {
       // нахождение траспонированной матрицы
       Matrix matrixt;
       unsigned m = content.size();
       unsigned n = content[0].size();
       for (unsigned j = 0; j < n; j++)
       {
           vectord line;
           for (unsigned i = 0; i < m; i++)
           {
               line.push_back(content[i][j]);
           }
           matrixt.content.push_back(line);
       }
       return matrixt;
   }


   Matrix Matrix::minor(unsigned i, unsigned j) const
   {
       // нахождение минора
       Matrix minor;
       unsigned m = content.size();
       unsigned n = content[0].size();
       for (unsigned k = 0; k < m; k++)
       {
           vectord line;
           for (unsigned l = 0; l < n; l++)
           {
               if (k != i && l != j)
               {
                   double e = content[k][l];
                   line.push_back(e);
               }
           }
           if (line.size() > 0)
           {
               minor.content.push_back(line);
           }
       }
       return minor;
   }



   double Matrix::det() const
   {
       // нахождение определителя
       unsigned n = content.size();
       double _det;
       if (n == 1)
       {
           _det = content[0][0];
           return _det;
       }
       if (n == 2)
       {
           _det = content[0][0]*content[1][1] - content[0][1]*content[1][0];
           return _det;
       }
       else
       {
           _det = 0.0;
           for (unsigned i = 0; i < 1; i++)
           {
               for (unsigned j = 0; j < n; j++)
               {
                   Matrix minor = this -> minor(i, j);
                   _det += pow(-1, i + j) * content[i][j] * minor.det();
               }
           }
           return _det;
       }
   }



   Matrix Matrix::inverse() const
   {
       // нахождение обратной матрицы
       double _det = this->det();
       if (_det == 0.0)
       {
           throw ZeroDivision;
           //   Determinant = 0. Can not find inverse matrix!!!
       }
       else
       {
           unsigned n = content.size();
           //matrixd matrix_inv = matrix;
           Matrix matr_inv;
           matr_inv.content = this->content;
           for (unsigned i = 0; i < n; i++)
           {
               for (unsigned j = 0; j < n; j++)
               {
                   Matrix minor = this -> minor(i, j);
                   matr_inv.content[i][j] = pow(-1, i + j) * minor.det();
               }
           }
           matr_inv = matr_inv.T();
           matr_inv = matr_inv * (1 / _det);
           return matr_inv;
       }
   }


   unsigned Matrix::size_W() const
   {
       return content[0].size();
   }


   unsigned Matrix::size_H() const
   {
       return content.size();
   }


   void Matrix::operator *= (const Matrix &matr)
   {
       // умножение матриц
       unsigned m1 = this->content.size();
       unsigned n1 = this->content[0].size();
       unsigned m2 = matr.content.size();
       unsigned n2 = matr.content[0].size();
       Matrix rezult(m1, n2);

       if (n1 != m2)
       {
           throw SizeError;
           /*  "The number of columns of the first matrix is"
            " ​​not equal to the number of rows of the second matrix!!!"*/
       }


       for (unsigned i = 0; i < m1; i++)
       {
           for (unsigned j = 0; j < n2; j++)
           {
               for (unsigned k = 0; k < n1; k++)
               {
                   rezult.content[i][j] += this->content[i][k] * matr.content[k][j];
               }
           }
       }

       this->content = rezult.content;
   }


   void Matrix::operator += (const Matrix &matr)
   {
       // сложение матриц
       unsigned m1 = this->content.size();
       unsigned n1 = this->content[0].size();
       unsigned m2 = matr.content.size();
       unsigned n2 = matr.content[0].size();

       if (m1 != m2 || n1 != n2)
       {
           throw SizeError;
           //  Matrices have different sizes!!!
       }

       for (unsigned i = 0; i < m1; i++)
       {
           for (unsigned j = 0; j < n1; j++)
           {
               this->content[i][j] += matr.content[i][j];
           }
       }
   }


   void Matrix::operator -= (const Matrix &matr)
   {
       // вычитание матриц
       unsigned m1 = this->content.size();
       unsigned n1 = this->content[0].size();
       unsigned m2 = matr.content.size();
       unsigned n2 = matr.content[0].size();

       if (m1 != m2 || n1 != n2)
       {
           throw SizeError;
           //  Matrices have different sizes!!!
       }

       for (unsigned i = 0; i < m1; i++)
       {
           for (unsigned j = 0; j < n1; j++)
           {
               this->content[i][j] -= matr.content[i][j];
           }
       }
   }


   void Matrix::operator *= (double num)
   {
       // умножение матрицы на скаляр
       unsigned m = this->content.size();
       unsigned n = this->content[0].size();
       for (unsigned i = 0; i < m; i++)
       {
           for (unsigned j = 0; j < n; j++)
           {
               this->content[i][j] *= num;
           }
       }
   }


   void Matrix::fill_matrix(FuncFillMatrix func)
   {
       // функция заполнения матрицы разными способами
       for (unsigned i = 0; i < content.size(); i++)
       {
           for (unsigned j = 0; j < content[0].size(); j++)
           {
               content[i][j] = func(content[i][j], i, j);
           }
       }
   }


   Matrix Matrix::replace_line(unsigned index) const
   {
       // функция смены нулевой и не нулевой строки
       vectord line;
       Matrix matr;
       matr.content = this->content;
       for (unsigned i = index + 1; i < this->size_H(); i++)
       {
           if (matr.content[i][index] != 0.0000)
           {
               line = matr.content[index];
               matr.content[index] = matr.content[i];
               matr.content[i] = line;
               return matr;
           }
       }
       return matr;
   }




   Matrix Matrix::method_gauss() const
   {
       //метод гаусса
       Matrix matra;
       Matrix matrb;
       matra.content = this->content;

       for (unsigned j = 0; j < this->size_W() - 2; j++)
       {
           if (matra.content[j][j] == 0.000)
           {
               matra = matra.replace_line(j);
           }


           if (matra.content[j][j] == 0.000)
           {
               throw ZeroDivision;
               /*
               In the matrix there is a zero column.
               There will be a division of nv zero. This column should be excluded !!!
               */
           }

           matrb = matra;

           for (unsigned i = j + 1; i < this->size_H(); i++)
           {
               for (unsigned k = j; k < this->size_W(); k++)
               {
                   matrb.content[i][k] = matrb.content[i][k] + (-matra.content[i][j] * matra.content[j][k]) / matra.content[j][j];
               }
           }

           matra = matrb;
       }

       return matra;
   }


   Matrix operator * (double num, Matrix &matr)
   {
       // умножение матрицы на скаляр
       unsigned m = matr.size_H();
       unsigned n = matr.size_W();
       Matrix rezult(m, n);
       for (unsigned i = 0; i < m; i++)
       {
           for (unsigned j = 0; j < n; j++)
           {
               rezult.content[i][j] =  num * matr.content[i][j];
           }
       }
       return rezult;
   }


   void Matrix::delta(Direction d)
   {
       for (unsigned i = 0; i < this->size_H(); i++)
       {
           for (unsigned j = 0; j < this ->size_W(); j++)
           {
               if ((i < j) && (d == up))
               {
                   content[i][j] = 0;
               }

               if ((i > j) && (d == down))
               {
                   content[i][j] = 0;
               }
           }
       }
   }
}
