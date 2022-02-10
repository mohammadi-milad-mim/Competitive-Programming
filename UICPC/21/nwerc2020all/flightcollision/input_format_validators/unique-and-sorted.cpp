#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n; cin >> n;

	vector<int> x(n), v(n);
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> v[i];
	}
	
	if (!is_sorted(begin(x), end(x))) exit(43);
	if (unique(begin(x), end(x)) != end(x)) exit(43);

	exit(42);
}
