#include "matrix.h"

using namespace std;

Matrix::Matrix(int height, int width) : height(height), width(width) {}

vector<Rational> &Matrix::operator[](int x){
	return array[x];
}

istream &operator >>(istream &input, Matrix &a){
	input >> a.height >> a.width;
	a.array.resize(a.height);
	for (int i = 0; i < a.height; i++){
		a.array[i].resize(a.width);
		for (int j = 0; j < a.width; j++)
			input >> a[i][j];
	}
	return input;
}

ostream &operator <<(ostream &output, Matrix x){
	for (int i = 0; i < x.height; i++){
		for (int j = 0; j < x.width; j++){
			if (j)
				output << " ";
			output << x[i][j];
		}
		output << endl;
	}
	return output;
}
//a[w1]+=a[w2]*x;
void Matrix::add_row(int w1, int w2, Rational x){
	for (int j = 0; j < width; j++)
		array[w1][j] += array[w2][j] * x;
}

void Matrix::swap_rows(int w1, int w2){
	swap(array[w1],array[w2]);
}

int Matrix::get_height(){
	return height;
}

int Matrix::get_width(){
	return width;
}