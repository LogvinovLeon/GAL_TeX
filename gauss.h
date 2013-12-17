#include "tex_writer.h"

class Gauss{

public:

	int find_pivot_row(Matrix &A, int i,int j);

	void solve(Matrix A, Matrix B);

};
