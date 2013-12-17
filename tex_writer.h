#include "matrix.h"

class Tex_Writer{

	FILE *file;

	std::string filename;

public:

	Tex_Writer(std::string filename);

	~Tex_Writer();

	void print_matrix(Matrix &A, char open_brace = '(', char close_brace = ')');

	void print_spec_symbol(std::string s);

	void begin_math();

	void end_math();
	
};