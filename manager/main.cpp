#include "result.hpp"
#include <cstdlib>
#include <iostream>
using namespace std;

int main() {
	int some = 1;
	int* p = &some;
	auto val = oj::Result<int>::ok(3);
	int v = val.unwrap_or_report([&]() {
		cout << &val << endl;
		exit(3);
		}
	);
	cout << v * 2 << endl;
}