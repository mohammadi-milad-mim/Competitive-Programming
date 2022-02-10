#include "validation.h"

int main(int argc, char** argv) {
	InputValidator v(argc, argv);
	int n = v.read_integer("n", 2, 1000000);
	v.space();
	int k = v.read_integer("k", 1, n - 1);
	v.newline();

	int a = v.read_integer("a", 0, 100);
	v.space();

	int b = v.read_integer("b", 0, 100);
	v.newline();
}
