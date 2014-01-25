#include "tex_writer.h"

class Gauss{

	Tex_Writer tex;

public:

	Gauss(std::string Filename = "output.tex");

	int find_pivot_row(Matrix &A, int i,int j);

	Matrix invert(Matrix &A);

	void reduce(Matrix &A, Matrix &B);

};
