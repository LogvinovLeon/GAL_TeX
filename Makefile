OBJECTS = rational.o matrix.o gauss.o tex_writer.o
TARGETS = main

.PHONY: all clean

all: main
	./main

main: main.cpp $(OBJECTS)
	g++ $(OBJECTS) main.cpp -o main

rational.o: rational.cpp rational.h rational.hpp
	g++ -c rational.cpp

matrix.o: matrix.cpp matrix.h
	g++ -c matrix.cpp

gauss.o: gauss.cpp gauss.h
	g++ -c gauss.cpp

tex_writer.o: tex_writer.cpp tex_writer.h
	g++ -c tex_writer.cpp