#include "tex_writer.h"

class Gauss
{

    Tex_Writer tex;

public:

    Gauss(std::string Filename = "output");

    int find_pivot_row(Matrix &A, int i, int j);

    Matrix invert(Matrix A);

    void reduce(Matrix &A, Matrix &B);

    Matrix multiply(Matrix A, Rational x);

    Matrix multiply(Matrix A, Matrix B);

    Matrix add(Matrix A, Matrix B);

};
