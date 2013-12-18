#include "matrix.h"

class Tex_Writer{

	FILE *file;

	std::string filename;

public:

	Tex_Writer(std::string filename);

	~Tex_Writer();

	void print_matrix(Matrix A, char open_brace = '(', char close_brace = ')');

	void print_string_vector(std::vector<std::string> v, char open_brace = '.', char close_brace = '.');

	void print_spec_symbol(std::string s);

	void begin_math();

	void end_math();

	std::string row_tex_format(int row);
	//c * row
	std::string get_transformation(Rational c, int row);
	//c1 * row_1 + c2 * row_2
	std::string get_transformation(Rational c1, int row_1, Rational c2, int row_2);
	
};