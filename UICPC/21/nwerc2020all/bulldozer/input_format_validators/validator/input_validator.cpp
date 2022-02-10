#include "validation.h"

int main(int argc, char** argv) {
	InputValidator v(argc, argv);
	int n = v.read_integer("n", 1, 200000);
	v.newline();
	v.read_integers("v", n, 0, 1000000000);
}
