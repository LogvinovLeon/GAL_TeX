#include "gauss.h"
#include <iostream>

using namespace std;

Matrix A, B;
Gauss G;
int main(){
	freopen("input.txt", "r", stdin);
	cin >> A >> B;
	G.solve(A,B);
}