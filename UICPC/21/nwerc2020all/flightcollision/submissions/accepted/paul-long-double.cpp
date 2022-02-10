#include <bits/stdc++.h>
using namespace std;

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

	set<tuple<long double, int, int>> collisions;

	auto add_collision = [&](int i, int j) {
		int a = p[i], b = p[j];
		if (v[a] == v[b]) return;
		long double t = (long double)(x[a]-x[b]) / (v[b]-v[a]);
		if (0 < t) collisions.emplace(t, i, j);
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
	cout << res.size();
	for (int i: res) cout << " " << i+1;
	cout << endl;
}
