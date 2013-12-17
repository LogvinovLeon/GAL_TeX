#include "gauss.h"
#include <iostream>

using namespace std;

Matrix A, B, C;
Tex_Writer tex("output");

int main(){
	freopen("input.txt", "r", stdin);
	cin >> A >> B;
	C = A * B;
	tex.begin_math();
	tex.print_matrix(C, '(', ')');
	tex.end_math();
}