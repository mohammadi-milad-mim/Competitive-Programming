#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int> a(n);
	for (int &x: a) cin >> x;
	sort(begin(a), end(a));
	
	deque<int> b(begin(a), end(a));

	vector<int> c;
	bool flip = true;
	while (!b.empty()) {
		if (flip) {
			c.push_back(b.front());
			b.pop_front();
		} else {
			c.push_back(b.back());
			b.pop_back();
		}
		flip = !flip;
	}
	reverse(begin(c), end(c));

	for (int x: c) cout << x << " ";
	cout << endl;
}
