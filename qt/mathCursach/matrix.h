#ifndef MATRIX_H
#define MATRIX_H


#include <iostream>
#include "myalgorithm.h"


template<typename T>
class Matrix
{
    using value_type = T;
    using pointer = value_type*;
    using matrix_pointer = pointer*;
    using reference = T&;
    using const_reference = const reference;
    using size_type = std::size_t;


    matrix_pointer m_array;
    value_type m_column;
    value_type m_row;
public:


    Matrix() = delete;
    Matrix(value_type row, value_type column): m_row(row), m_column(column) //Matrix a(3, 3) "3x3 matrix initialized"
    {
        m_array = new pointer[m_row];
        for(int i = 0; i != m_row; ++i)
        {
            m_array[i] = new value_type[m_column];
        }
    }
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//feature list
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    void pull_matrix(size_type coloum, size_type row, value_type element); // matrix fill
    void print_matrix(); // matrix print
    void operator=(value_type value); // a = 4 "all elements of the matrix are equal to four"
    void operator+(value_type value); // a + 4 "the whole matrix are summed with 4"
    void operator-(value_type value); // a - 4 "four will be deducted from all elements of the matrix"
    void operator*(value_type value); // a * 4 "all elements of the matrix will ​​multiply by 4"
    void operator/(value_type value); // a / 4 "all elements of the matrix will divide by 4"
    Matrix operator*(const Matrix that); // a = a * b "matrix multiplication by matrix"
    Matrix operator-(const Matrix that); // a = a - b "subtract matrix from matrix"
    Matrix operator+(const Matrix that); // a = a + b "matrix addition from matrix"
    Matrix minor(value_type d_colum, value_type d_row);// Matrix x = a.find_minor(0, 0) "find matrix minor 0x0"
    Matrix range_minor(value_type i, value_type j, value_type m_size);// Matrix x = a.find_minor(0, 0, 3) "find matrix minor 0x0 in range 3"
    value_type algebroic_add(value_type d_colum, value_type d_row); // Matrix<int> b = a.algebroic_add(4, 4) "the function of finding the algebraic matrix complement"
    value_type find_det();// int temp = a.find_det(); "matrix recursive determinant function"
    value_type find_range();// int temp = a.find_rang(); "matrix rank finding function"


    ~Matrix()
    {
        for(T i = 0; i < m_row; ++i)
        {
            delete m_array[i];
        }
        delete[] m_array;
    }
};



template<typename T>
void Matrix<T>::pull_matrix(Matrix::size_type coloum, Matrix::size_type row, Matrix::value_type element)
{
    m_array[row][coloum] = element;
}

template<typename T>
void Matrix<T>::print_matrix()
{
    for(T i = 0; i != m_row; i++)
    {
        for(T j = 0; j != m_column; j++)
        {
            std::cout << m_array[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

template<typename T>
void Matrix<T>::operator=(T value)
{
    for(T i = 0; i != m_row; i++)
    {
        for(T j = 0; j != m_column; j++)
        {
            m_array[i][j] = value;
        }
    }
}

template<typename T>
void Matrix<T>::operator+(T value)
{
    for(T i = 0; i != m_row; i++)
    {
        for(T j = 0; j != m_column; j++)
        {
            m_array[i][j] += value;
        }
    }
}

template<typename T>
void Matrix<T>::operator-(T value)
{
    for(T i = 0; i != m_row; i++)
    {
        for(T j = 0; j != m_column; j++)
        {
            m_array[i][j] -= value;
        }
    }
}

template<typename T>
void Matrix<T>::operator*(T value)
{
    for(T i = 0; i != m_row; i++)
    {
        for(T j = 0; j != m_column; j++)
        {
            m_array[i][j] *= value;
        }
    }
}

template<typename T>
void Matrix<T>::operator/(T value)
{
    for(T i = 0; i != m_row; i++)
    {
        for(T j = 0; j != m_column; j++)
        {
            m_array[i][j] /= value;
        }
    }
}

template<typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T> that)
{
    stu::correct_conditions(m_column, that.m_row);
    stu::correct_conditions(that.m_column, m_row);
    Matrix<T> result(that.m_column, m_row);
    result = 0;
    for (T i = 0; i != m_row; i++)
    {
        for (T j = 0; j != that.m_column; j++)
        {
            for (T k = 0; k != that.m_row; k++)
            {
                result.m_array[i][j] += m_array[i][k] * that.m_array[k][j];
            }
        }
    }
    return result;
}

template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T> that)
{
    Matrix<T> result(that.m_column, m_row);
    for (T i = 0; i != m_row; i++)
    {
        for (T j = 0; j != m_column; j++)
        {
            result.m_array[i][j] = m_array[i][j] + that.m_array[i][j];
        }
    }
    return result;
}

template<typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T> that)
{
    Matrix<T> result(that.m_column, m_row);
    for (T i = 0; i != m_row; i++)
    {
        for (T j = 0; j != m_column; j++)
        {
            result.m_array[i][j] = m_array[i][j] - that.m_array[i][j];
        }
    }
    return result;
}

template<typename T>
Matrix<T> Matrix<T>::minor(T d_colum, T d_row)
{
    Matrix result(m_row - 1, m_column - 1);
    int c = 0;
    int r = 0;
    for(T i = 0; i != m_row; i++)
    {
        for(T j = 0; j != m_column; j++)
        {
            if(i != d_row && j != d_colum)
            {
                result.m_array[r][c] = m_array[i][j];
                stu::matrix_jumping(r, c, m_column - 1);
            }
        }
    }
    return result;
}

template<typename T>
Matrix<T> Matrix<T>::range_minor(T i, T j, T range)
{
    Matrix result(range, range);
    T i_range = i;
    T j_range = j;
    for(T a = -1; i != range + i_range; i++)
    {
        a++;
        j = j_range;
        for(T b = -1; j != range + j_range; j++)
        {
            b++;
            result.m_array[a][b] = m_array[i][j];
        }
    }
    return result;
}

template<typename T>
T Matrix<T>::algebroic_add(T d_colum, T d_row)
{
    Matrix m_minor = minor(d_colum, d_row);
    int temp = stu::pow(-1, d_colum + d_row + 2) * m_array[d_row][d_colum];
    m_minor * temp;
    T res = m_minor.find_det();
    return res;
}

template<typename T>
T Matrix<T>::find_det()
{
    stu::correct_conditions(m_row, m_column);
    T m_size = m_row;
    T result = 0;
    if(m_size == 1)
    {
        return this->m_array[0][0];
    }
    else
    {
        if(m_size == 2)
        {
            return this->m_array[0][0] * this->m_array[1][1] - this->m_array[0][1] * this->m_array[1][0];
        }
        else
        {
            Matrix temp(m_size - 1, m_size - 1);
            T a, b;
            for(int j = 0; j < m_size; ++j)
            {
                a = 0;
                for(T r = 1; r != m_size; r++)
                {
                    b = 0;
                    for(T c = 0; c != m_size; c++)
                    {
                        if(c != j)
                        {
                            temp.m_array[a][b] = this->m_array[r][c];
                            b++;
                        }
                    }
                    a++;
                }
                result += stu::pow(-1, j) * this->m_array[0][j] * temp.find_det();
            }
        }
    }
    return result;
}

template<typename T>
T Matrix<T>::find_range()
{
    T m_size = stu::find_min(m_column, m_row);
    T range = 1;
    for(T i = 0; i != m_row; i++)
    {
        for(T j = 0; j != m_column; j++)
        {
            if(range <= m_size && range + i <= m_row && range + j <= m_column)
            {
                Matrix result = range_minor(i, j, range);
                result.print_matrix();
                if(result.find_det() != 0)
                {
                    range++;
                    i = 0;
                    j = 0;
                }
            }
        }
    }
    range -= 1;
    return range;
}




#endif // MATRIX_H
