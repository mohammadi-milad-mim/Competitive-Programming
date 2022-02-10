#include "validation.h"

int main(int argc, char** argv) {
	InputValidator v(argc, argv);
	int n = v.read_integer("n", 1, 400);
	v.newline();
	v.read_integers("d", n, 1, 1000000);
	for(int i = 0; i < 3; ++i) {
		v.read_integers("t", n, 1, 1000000);
	}
}
