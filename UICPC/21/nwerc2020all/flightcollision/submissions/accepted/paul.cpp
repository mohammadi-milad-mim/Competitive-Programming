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

int main() {
	int n; cin >> n;

	vector<int> x(n), v(n);
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> v[i];
	}

	vector<int> p(n);
	iota(begin(p), end(p), 0);
	sort(begin(p), end(p), [&](int i, int j) { return x[i] < x[j]; });
	
	set<int> remaining;
	for (int i = 0; i < n; i++) remaining.insert(i);

	fraction zero(0,1);

	set<tuple<fraction, int, int>> collisions;

	auto add_collision = [&](int i, int j) {
		int a = p[i], b = p[j];
		if (v[a] == v[b]) return;
		fraction t(x[a]-x[b], v[b]-v[a]);
		if (zero < t) collisions.emplace(t, i, j);
	};

	for (int i = 0; i+1 < n; i++) {
		add_collision(i, i+1);
	}
	
	while (!collisions.empty()) {
		auto [t,i,j] = *begin(collisions);
		collisions.erase(begin(collisions));
		
		if (!remaining.count(i) || !remaining.count(j)) continue;
		
		remaining.erase(i);
		remaining.erase(j);

		auto it = remaining.lower_bound(i);
		if (it != begin(remaining) && it != end(remaining)) {
			add_collision(*prev(it), *it);
		}
	}
	
	set<int> res;
	for (int i: remaining) res.insert(p[i]);
	cout << res.size() << endl;
	bool first = true;
	for (int i: res) {
		if (first) first = false;
		else cout << " ";
		cout << i+1;
	}
	cout << endl;
}
