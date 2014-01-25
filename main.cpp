#include "gauss.h"
#include <iostream>

using namespace std;

Matrix A, B, C;
Gauss G;

int main(){
	freopen("input.txt", "r", stdin);
	cin >> A >> B;
	cout<<Rational(3)*A<<endl;
	cout<<G.multiply(A, B)<<endl;
	cout<<G.multiply(B, A)<<endl;
	cout<<G.multiply(A, G.invert(A))<<endl;
}