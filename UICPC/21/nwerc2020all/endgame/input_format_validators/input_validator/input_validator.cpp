#include "validation.h"

int main(int argc, char** argv) {
	InputValidator v(argc, argv);
	int n = v.read_integer("n", 2, 100000);
	v.newline();

	int ax = v.read_integer("ax", 1, n);
	v.space();
	int ay = v.read_integer("ay", 1, n);
	v.newline();
	int bx = v.read_integer("bx", 1, n);
	v.space();
	int by = v.read_integer("by", 1, n);
	v.newline();

	std::set<std::pair<int, int>> moves;
	for(int i = 0; i < n; ++i) {
		int x = v.read_integer("x", -n + 1, n - 1);
		v.space();
		int y = v.read_integer("y", -n + 1, n - 1);
		v.newline();
		moves.insert({x, y});
	}

	v.check(moves.size() == n, "Duplicate moves!");
}
