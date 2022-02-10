#include "validation.h"

int main(int argc, char** argv) {
	InputValidator v(argc, argv);
	int n = v.read_integer("n", 2, 5000);
	v.space();
	int r = v.read_integer("r", n+1, 5000);
	v.space();
	int m = v.read_integer("m", 1, 50);
	v.newline();

	int last_t = 0;
	for(int i = 0; i < m; ++i){
		last_t = v.read_integer("t", last_t+1, n-1);
		v.space();
		v.read_float("p", 0.000000999, 1-0.00000099);
		v.space();
		v.read_integer("d", 1, 1000);
		v.newline();
	}
}
