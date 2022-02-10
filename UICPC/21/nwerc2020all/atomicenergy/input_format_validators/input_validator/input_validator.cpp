#include "validation.h"

int main(int argc, char** argv) {
	InputValidator v(argc, argv);
	int n = v.read_integer("n", 1, 100);
	v.space();
	int q = v.read_integer("q", 1, 100'000);
	v.newline();
	v.read_integers("a", n, 1, 1'000'000'000);
	v.read_integers("q", q, 1, 1'000'000'000, Arbitrary, Newline);
}
