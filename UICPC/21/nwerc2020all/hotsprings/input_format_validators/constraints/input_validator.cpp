#include "validation.h"

int main(int argc, char** argv) {
	InputValidator v(argc, argv);
	int n = v.read_integer("n", 2, 100000);
	v.newline();
	v.read_integers("t", n, -100000, 100000);
}
