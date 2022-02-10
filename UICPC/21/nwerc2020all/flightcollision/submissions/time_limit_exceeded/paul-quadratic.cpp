#include <bits/stdc++.h>
using namespace std;

struct fraction {
	long a, b;
	
	fraction(long c, long d): a(c), b(d) {
		long g = gcd(a,b);
		a /= g, b /= g;
		if (b < 0) a = -a, b = -b;
	}
	
	bool operator<(const fraction &f) const {
		return a*f.b < f.a*b;
	}
};

const fraction zero(0,1);

int main() {
	int n; cin >> n;

	vector<int> x(n), v(n);
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> v[i];
	}
	
	vector<int> p(n);
	iota(begin(p), end(p), 0);
	sort(begin(p), end(p), [&](int i, int j) { return x[i] < x[j]; });
	
	list<int> remaining(begin(p), end(p));
	
	while (true) {
		fraction best(1,0);
		auto collision = end(remaining);
		
		for (auto it = begin(remaining); next(it) != end(remaining); it++) {
			int i = *it, j = *next(it);
			fraction cur(x[i]-x[j], v[j]-v[i]);
			if (cur < zero) continue;
			if (cur < best) best = cur, collision = it;
		}
		
		if (collision == end(remaining)) break;
		
		remaining.erase(next(collision));
		remaining.erase(collision);
	}
	
	set<int> res;
	for (int i: remaining) res.insert(i);
	cout << res.size();
	for (int i: res) cout << " " << i+1;
	cout << endl;
}
