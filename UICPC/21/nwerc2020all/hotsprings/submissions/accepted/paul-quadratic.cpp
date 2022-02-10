#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int> a(n);
	for (int &x: a) cin >> x;
	sort(begin(a), end(a));
	
	vector<int> c;
	bool flip = true;
	while (!a.empty()) {
		if (flip) {
			c.push_back(a.front());
			a.erase(begin(a));
		} else {
			c.push_back(a.back());
			a.pop_back();
		}
		flip = !flip;
	}
	reverse(begin(c), end(c));

	for (int x: c) cout << x << " ";
	cout << endl;
}
