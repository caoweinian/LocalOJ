#include "program.h"
#include <iostream>
#include <cstdlib>

int main(int argc, const char **argv)
{
	using i32 = oj::i32;

	auto p = oj::program::from(argc, argv);
	p.unwrap_or_report([&](){
		oj::report_and_exit(p.get_error());
	}).run();
	// return 0;
}