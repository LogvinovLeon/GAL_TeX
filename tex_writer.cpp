#include "tex_writer.h"

using namespace std;

Tex_Writer::Tex_Writer(string _filename){
	filename = _filename;
	file = fopen((filename + ".tex").c_str(), "w");
	fprintf(file, "\\documentclass[a4paper,11pt]{article}\n");
	fprintf(file, "\\usepackage[utf8]{inputenc}\n");
	fprintf(file, "\\usepackage[MeX]{polski}\n");
	fprintf(file, "\\usepackage{latexsym}\n");
	fprintf(file, "\\usepackage{xfrac}\n");
	fprintf(file, "\\usepackage{breqn}\n");
	fprintf(file, "\\begin{document}\n");
}

Tex_Writer::~Tex_Writer(){
	fprintf(file, "\\end{document}\n");
	fclose(file);
	system(("pdflatex " + filename + ".tex").c_str());
	system(("open " + filename + ".pdf").c_str());
}

void Tex_Writer::print_matrix(Matrix A, char open_brace, char close_brace){
	
	fprintf(file, "\\left %c\n", open_brace);
	fprintf(file, "\\begin{array}{");
	for (int i = 0; i < A.get_width(); ++i)
		putc('c', file);
	fprintf(file, "}\n");
	for (int i = 0; i < A.get_height(); ++i)
		for (int j = 0; j < A.get_width(); ++j){
			fprintf(file, "%s ", A[i][j].to_tex_str().c_str());
			if (j + 1 < A.get_width())
				fprintf(file, "& ");
			else
				fprintf(file, "\\cr\n");
		}
	fprintf(file, "\\end{array}\n");
	fprintf(file, "\\right %c\n", close_brace);
}

void Tex_Writer::print_string_vector(vector<string> v, char open_brace, char close_brace){
	fprintf(file, "\\left %c\n", open_brace);
	fprintf(file, "\\begin{array}{");
	putc('r', file);
	fprintf(file, "}\n");
	for (int i = 0; i < v.size(); ++i)
		fprintf(file, "%s \\cr\n", v[i].c_str());
	fprintf(file, "\\end{array}\n");
	fprintf(file, "\\right %c\n", close_brace);
}

void Tex_Writer::put_equality(){
	fprintf(file, "=\n");
}

void Tex_Writer::print_spec_symbol(string s){
	fprintf(file, "\\%s\n", s.c_str());
}

void Tex_Writer::begin_math(){
	fprintf(file, "\\begin{dmath*}\n");
}

void Tex_Writer::end_math(){
	fprintf(file, "\\end{dmath*}\n");
}

string Tex_Writer::row_tex_format(int row){
	return "W_" + cast<string>(row);
}

string Tex_Writer::get_transformation(Rational c, int row){
	if ((row == 0) || (c == Rational(0)))
		return "";
	if (c == Rational(1))
		return row_tex_format(row);
	if (c == Rational(-1))
		return "-" + row_tex_format(row);
	return c.to_tex_str() + row_tex_format(row);
}

string Tex_Writer::get_transformation(Rational c_1, int row_1, Rational c_2, int row_2){
	if ((row_1 == 0) || (c_1 == Rational(0)))
		return get_transformation(c_2, row_2);
	if ((row_2 == 0) || (c_2 == Rational(0)))
		return get_transformation(c_1, row_1);
	if (c_1 < c_2){
		swap(c_1, c_2);
		swap(row_1, row_2);
	}
	string part_1 = get_transformation(c_1, row_1), 
		   part_2 = get_transformation(c_2, row_2);
	if (part_2[0] == '-')
		return part_1 + part_2;
	else
		return part_1 + "+" + part_2;
}