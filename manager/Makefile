manage: main.o result.o error.o argparse.o batchpcs.o program.o
	g++ -std=c++17 main.o result.o error.o argparse.o batchpcs.o program.o -o ../miniOJ
main.o: main.cpp
	g++ -std=c++17 main.cpp -o main.o
result.o: result.hpp
	g++ -std=c++17 result.hpp -o result.o
error.o: error.h error.cpp
	g++ -std=c++17 error.cpp -o error.o
argparse.o: argparse.h argparse.cpp
	g++ -std=c++17 argparse.cpp result.hpp -o argparse.o
batchpcs.o: batchpcs.h batchpcs.cpp
	g++ -std=c++17 batchpcs.cpp -o batchpcs.o
program.o: program.h program.cpp
	g++ -std=c++17 program.cpp -o program.o
clean:
	rm main.o result.o error.o argparse.o batchpcs.o program.o