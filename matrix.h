#include <vector>
#include "rational.h"

class Matrix{
	
	int height, width;
	std::vector<std::vector<Rational> > array;
	
public:

	Matrix(int height = 0, int width = 0);
	
	std::vector<Rational> &operator[](int x);
	
	friend std::istream &operator >>(std::istream &input, Matrix &a);

	friend std::ostream &operator <<(std::ostream &output, Matrix x);
	//a[w1]+=a[w2]*x;
	void add_row(int w1, int w2, Rational x);

	void swap_rows(int w1, int w2);

	int get_height();

	int get_width();

};