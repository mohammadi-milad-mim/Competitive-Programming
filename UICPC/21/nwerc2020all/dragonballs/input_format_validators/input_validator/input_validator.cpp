#include "validation.h"

#include <set>
using namespace std;

int main(int argc, char** argv) {
	InputValidator v(argc, argv);
	int n = v.read_integer("n", 1, 7);
	v.newline();

	set<pair<int, int>> points;
	for(int i = 0; i < n; ++i) {
		int x = v.read_integer("x", 0, 1000000);
		v.space();
		int y = v.read_integer("y", 0, 1000000);
		v.newline();
		points.insert({x, y});
	}
	v.check(points.size() == n, "Found duplicate points!");
}
