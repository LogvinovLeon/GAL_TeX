#include "gauss.h"
#include <iostream>
#include <cstdio>

using namespace std;

Matrix A, B, C;
Gauss G;

int main()
{
    freopen("input.txt", "r", stdin);
    cin >> A >> B;
    G.reduce(A, B);
}
