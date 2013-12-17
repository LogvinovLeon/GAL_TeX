#include "gauss.h"
#include <iostream>
#include <cassert>
#include <memory.h>

using namespace std;

int Gauss::find_pivot_row(Matrix &A, int i, int j){
	assert(i < A.get_height());
	int max_element_row = i;
	for (int row = i + 1; row < A.get_height(); row++)
		if (abs(A[row][j]) > abs(A[max_element_row][j]))
			max_element_row = row;
	return max_element_row;
}

void Gauss::solve(Matrix A, Matrix B){
	assert(A.get_height() == B.get_height());
	Tex_Writer tex("output");
	tex.begin_math();
	tex.print_matrix(A, '(', '|');
	tex.print_matrix(B, '.', ')');
	int n = A.get_height(),
		m = A.get_width(),
		k = B.get_width();
	bool free_variable[m];
	memset(free_variable, 1, m);
	for (int step = 0; step < std::min(n, m); step++){
		tex.print_spec_symbol("leadsto");
		int pivot_row = find_pivot_row(A, step, step);
		if (A[pivot_row][step] != Rational(0)){
			free_variable[step] = 0;
			B.swap_rows(pivot_row, step);
			A.swap_rows(pivot_row, step);
			B.add_row(step, step, Rational(1) / A[step][step] - Rational(1));
			A.add_row(step, step, Rational(1) / A[step][step] - Rational(1));
			for (int row = 0; row < n; row++){
				if (row == step)
					continue;
				B.add_row(row, step, -A[row][step]);
				A.add_row(row, step, -A[row][step]);
			}
		}
		tex.print_matrix(A, '(', '|');
		tex.print_matrix(B, '.', ')');
	}
	tex.end_math();
}