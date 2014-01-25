#include "gauss.h"
#include <iostream>

using namespace std;

Matrix A, B, C;
Gauss G;

int main(){
	freopen("input.txt", "r", stdin);
	cin >> A;
	cout<<G.invert(A)*A<<endl;
}