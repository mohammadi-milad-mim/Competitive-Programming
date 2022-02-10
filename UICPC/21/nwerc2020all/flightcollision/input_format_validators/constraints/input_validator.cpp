#include "validation.h"

int main(int argc, char** argv) {
	InputValidator v(argc, argv);
	int n = v.read_integer("n", 1, 100000);
	v.newline();

	int last_x = -1000000000 - 1;
	for(int i = 0; i < n; ++i) {
		int x = v.read_integer("x", last_x + 1, 1000000000);
		v.space();
		int y = v.read_integer("x", -1000000000, 1000000000);
		v.newline();
		last_x = x;
	}
}
