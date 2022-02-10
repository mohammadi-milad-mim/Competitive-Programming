#include "validation.h"

int main(int argc, char** argv) {
	InputValidator v(argc, argv);
	std::string s = v.read_line("s", 1, 999);
	std::string t = v.read_line("t", 2, 1000);
	v.check(s.size() < t.size(), "t is not longer than s!");
}
