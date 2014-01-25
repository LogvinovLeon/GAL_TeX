#include "gauss.h"
#include <iostream>

using namespace std;

Matrix A, B, C;
Gauss G;

int main(){
	freopen("input.txt", "r", stdin);
	cin >> A >> B;
	G.multiply(A, B);
	G.multiply(A, Rational(-4));
	G.add(A, B);
	G.invert(A);
	G.multiply(A, G.invert(A)*Rational(-1));
	G.reduce(A,B);
}