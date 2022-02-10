// Checks that there is no collision between three or more cars.
#include <algorithm>
#include <iostream>
#include <numeric>
#include <set>
#include <tuple>
#include <vector>
using namespace std;

const int VALID_DATA     = 42; // Exit code if input is valid.
const int INVALID_DATA   = 43; // Exit code if input is invalid.
const int VALIDATE_ERROR = 44; // Exit code if there is an error (should never happen).

struct fraction {
	int a, b;

	fraction(int c, int d): a(c), b(d) {
		int g = gcd(a,b);
		a /= g, b /= g;
		if (b < 0) a = -a, b = -b;
	}

	bool operator==(const fraction &f) const {
		return a == f.a && b == f.b;
	}

	bool operator<(const fraction &f) const {
		return (long long) a * f.b < (long long) f.a * b;
	}
};

const fraction zero(0,1);

int main() {
	int n; cin >> n;

	vector<int> x(n), v(n);
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> v[i];
	}

	// Simulate the process using a priority queue of collisions between adjacent vehicles:

	// Set of still existing vehicles.
	set<int> remaining;
	for (int i = 0; i < n; i++) remaining.insert(i);

	// Priority queue of collisions, i.e. triples [time, lower index, higher index].
	set<tuple<fraction, int, int>> collisions;

	auto add_collision = [&](int i, int j) {
		if (v[i] == v[j]) return;
		fraction t(x[i]-x[j], v[j]-v[i]);
		if (zero < t) {
			collisions.emplace(t, i, j);
		}
	};

	auto remove_collision = [&](int i, int j) {
		if (v[i] == v[j]) return;
		fraction t(x[i]-x[j], v[j]-v[i]);
		if (zero < t) {
			if (!collisions.erase(make_tuple(t,i,j))) exit(VALIDATE_ERROR);
		}
	};

	for (int i = 0; i+1 < n; i++) {
		add_collision(i, i+1);
	}

	while (!collisions.empty()) {
		// Vehicles i and j collide at time t.
		auto [t,i,j] = *begin(collisions);
		collisions.erase(begin(collisions));

		// Make sure that both vehicles still exist, delete them.
		if (!remaining.erase(i)) exit(VALIDATE_ERROR);
		if (!remaining.erase(j)) exit(VALIDATE_ERROR);

		// Find the two neighbouring indices to the left and right.
		auto it = remaining.lower_bound(i);
		int h = it != begin(remaining) ? *prev(it) : -1;
		int k = it != end(remaining) ? *it : -1;

		// Check whether another vehicle is involved in the same crash.
		// Due to the sorting of the priority queue this happens iff
		// the next element in the queue is the triple [t,j,k].
		if (!collisions.empty()) {
			auto [s,jj,kk] = *begin(collisions);
			if (t == s && jj == j && kk == k) {
				fprintf(stderr, "Crash involving three cars: (%d,%d) (%d,%d) (%d,%d)\n",
						x[i], v[i], x[j], v[j], x[k], v[k]);
				exit(INVALID_DATA);
			}
		}

		// Erase collisions involving i or j and add a new one between h and k.
		if (h != -1) remove_collision(h, i);
		if (k != -1) remove_collision(j, k);
		if (h != -1 && k != -1) add_collision(h, k);
	}

	exit(VALID_DATA);
}
