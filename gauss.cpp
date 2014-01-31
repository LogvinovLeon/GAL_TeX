#include "gauss.h"
#include <iostream>
#include <cassert>
#include <memory.h>
#include <vector>

using namespace std;

Gauss::Gauss(string Filename) : tex(Filename) {}

int Gauss::find_pivot_row(Matrix &A, int i, int j)
{
    assert(i < A.get_height());
    int max_element_row = i;
    for (int row = i + 1; row < A.get_height(); row++)
        if ((abs(A[row][j]) != Rational(0)) && (abs(A[row][j]) < abs(A[max_element_row][j])))
            max_element_row = row;
    return max_element_row;
}

Matrix Gauss::invert(Matrix A)
{
    assert(A.get_height() == A.get_width());
    Matrix I = Matrix(A.get_height());
    reduce(A, I);
    return I;
}

void Gauss::reduce(Matrix &A, Matrix &B)
{
    assert(A.get_height() == B.get_height());
    tex.begin_math();
    tex.print_matrix(A, '(', '|');
    tex.print_matrix(B, '.', ')');
    int n = A.get_height(),
        m = A.get_width(),
        k = B.get_width();
    for (int step = 0; step < std::min(n, m); step++)
    {
        tex.put_string("=");
        int pivot_row = find_pivot_row(A, step, step);
        vector<string> transformations(n);
        if (A[pivot_row][step] != Rational(0))
        {
            Rational c = A[pivot_row][step];
            B.swap_rows(pivot_row, step);
            A.swap_rows(pivot_row, step);
            B.add_row(step, step, Rational(1) / A[step][step] - Rational(1));
            A.add_row(step, step, Rational(1) / A[step][step] - Rational(1));
            for (int row = 0; row < n; row++)
            {
                if (row == step)
                {
                    transformations[row] = tex.get_transformation(Rational(1) / c, pivot_row + 1);
                    continue;
                }
                if (row == pivot_row)
                    transformations[row] = tex.get_transformation(Rational(1), step + 1, - A[row][step] / c, pivot_row + 1);
                else
                    transformations[row] = tex.get_transformation(Rational(1), row + 1, - A[row][step] / c, pivot_row + 1);
                B.add_row(row, step, -A[row][step]);
                A.add_row(row, step, -A[row][step]);
            }
        }
        tex.print_string_vector(transformations);
        tex.print_matrix(A, '(', '|');
        tex.print_matrix(B, '.', ')');
    }
    tex.end_math();
}

Matrix Gauss::multiply(Matrix A, Rational x)
{
    tex.begin_math();
    tex.print_matrix(A);
    tex.print_spec_symbol("cdot");
    tex.put_string(x.to_tex_str());
    tex.put_string("=");
    tex.print_matrix(A * x);
    tex.end_math();
    return A * x;
}

Matrix Gauss::multiply(Matrix A, Matrix B)
{
    tex.begin_math();
    tex.print_matrix(A);
    tex.print_spec_symbol("cdot");
    tex.print_matrix(B);
    tex.put_string("=");
    tex.print_matrix(A * B);
    tex.end_math();
    return A * B;
}

Matrix Gauss::add(Matrix A, Matrix B)
{
    tex.begin_math();
    tex.print_matrix(A);
    tex.put_string("+");
    tex.print_matrix(B);
    tex.put_string("=");
    tex.print_matrix(A + B);
    tex.end_math();
    return A + B;
}