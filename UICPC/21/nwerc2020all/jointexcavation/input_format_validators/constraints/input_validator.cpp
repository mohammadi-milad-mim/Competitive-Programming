#include "validation.h"

int main(int argc, char** argv) {
	InputValidator v(argc, argv);
	int c = v.read_integer("c", 1, 200000);
	v.space();
	int t = v.read_integer("t", 0, 200000);
	v.newline();
	std::set<std::pair<int, int>> edges;
	for(int i = 0; i < t; ++i) {
		int a = v.read_integer("a", 1, c);
		v.space();
		int b = v.read_integer("b", 1, c);
		v.newline();
		v.check(a != b, "Found a loop!");
		if(a > b) std::swap(a, b);
		edges.insert({a, b});
	}
	v.check(edges.size() == t, "Found duplicate edges!");
}
