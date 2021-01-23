complie = g++ -std=c++17 -O2
objs = main.o error.o argparse.o batchpcs.o program.o
target_dir = ../miniOJ
bin_name = manage
manage: $(objs)
	$(complie) $(objs) -o $(target_dir)/$(bin_name)
main.o: main.cpp argparse.o
	$(complie) -c main.cpp -o main.o
error.o: error.cpp
	$(complie) -c error.cpp -o error.o
argparse.o: argparse.cpp error.o
	$(complie) -c argparse.cpp -o argparse.o
batchpcs.o: batchpcs.cpp
	$(complie) -c batchpcs.cpp -o batchpcs.o
program.o: program.cpp
	$(complie) -c program.cpp -o program.o
clean:
	rm $(objs)