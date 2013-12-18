#include "tex_writer.h"

Tex_Writer::Tex_Writer(std::string _filename){
	filename = _filename;
	file = fopen((filename + ".tex").c_str(), "w");
	fprintf(file, "\\documentclass[a4paper,11pt]{article}\n");
	fprintf(file, "\\usepackage[utf8]{inputenc}\n");
	fprintf(file, "\\usepackage[MeX]{polski}\n");
	fprintf(file, "\\usepackage{latexsym}\n");
	fprintf(file, "\\usepackage{xfrac}\n");
	fprintf(file, "\\begin{document}\n");
}

Tex_Writer::~Tex_Writer(){
	fprintf(file, "\\end{document}\n");
	fclose(file);
	system(("pdflatex " + filename + ".tex").c_str());
	system(("open " + filename + ".pdf").c_str());
}

void Tex_Writer::begin_math(){
	fprintf(file, "\\begin{math}\n");
}

void Tex_Writer::end_math(){
	fprintf(file, "\\end{math}\n");
}

void Tex_Writer::print_matrix(Matrix A, char open_brace, char close_brace){
	
	fprintf(file, "\\left %c\n", open_brace);
	fprintf(file, "\\begin{array}{");
	for (int i = 0; i < A.get_height(); ++i)
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

void Tex_Writer::print_spec_symbol(std::string s){
	fprintf(file, "\\%s", s.c_str());
}