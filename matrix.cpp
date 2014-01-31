#include "matrix.h"
#include <cassert>
using namespace std;

Matrix::Matrix(int size) : height(size), width(size)
{
    array.resize(height);
    for (int i = 0; i < height; ++i)
    {
        array[i].resize(size);
        array[i][i] = Rational(1);
    }
}

Matrix::Matrix(int height, int width) : height(height), width(width)
{
    array.resize(height);
    for (int i = 0; i < height; ++i)
        array[i].resize(width);
}

vector<Rational> &Matrix::operator[](int x)
{
    return array[x];
}

istream &operator >>(istream &input, Matrix &a)
{
    input >> a.height >> a.width;
    a.array.resize(a.height);
    for (int i = 0; i < a.height; i++)
    {
        a.array[i].resize(a.width);
        for (int j = 0; j < a.width; j++)
            input >> a[i][j];
    }
    return input;
}

ostream &operator <<(ostream &output, Matrix x)
{
    for (int i = 0; i < x.height; i++)
    {
        for (int j = 0; j < x.width; j++)
        {
            if (j)
                output << " ";
            output << x[i][j];
        }
        output << endl;
    }
    return output;
}

Matrix Matrix::operator *(Rational x)
{
    Matrix C(this->get_height(), this->get_width());
    for (int i = 0; i < C.get_height(); ++i)
        for (int j = 0; j < C.get_width(); ++j)
            C[i][j] = (*this)[i][j] * x;
    return C;
}

Matrix Matrix::operator *(Matrix &A)
{
    assert(this->get_width() == A.get_height());
    Matrix C(this->get_height(), A.get_width());
    for (int i = 0; i < C.get_height(); ++i)
        for (int j = 0; j < C.get_width(); ++j)
            for (int k = 0; k < this->get_width(); ++k)
                C[i][j] += (*this)[i][k] * A[k][j];
    return C;
}

Matrix Matrix::operator +(Matrix &A)
{
    assert((this->get_height() == A.get_height()) && (this->get_width() == A.get_width()));
    Matrix C(this->get_height(), this->get_width());
    for (int i = 0; i < C.get_height(); ++i)
        for (int j = 0; j < C.get_width(); ++j)
            C[i][j] = (*this)[i][j] + A[i][j];
    return C;
}

//a[w1]+=a[w2]*x;
void Matrix::add_row(int w1, int w2, Rational x)
{
    for (int j = 0; j < width; j++)
        array[w1][j] += array[w2][j] * x;
}

void Matrix::swap_rows(int w1, int w2)
{
    swap(array[w1], array[w2]);
}

int Matrix::get_height()
{
    return height;
}

int Matrix::get_width()
{
    return width;
}