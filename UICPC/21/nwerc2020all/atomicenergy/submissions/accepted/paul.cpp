#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 3e4;

int main() {
	int n, q;
	cin >> n >> q;

	vector<ll> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	for (; n < N; n++) {
		ll cur = 1e18;
		for (int i = 0; i <= n-1-i; i++) {
			cur = min(cur, a[i]+a[n-1-i]);
		}
		a.push_back(cur);
	}
	
	int k = 1;
	ll step = -1;
	for (; ; k++) {
		step = a[n-1] - a[n-1-k];
		bool ok = true;
		for (int i = n-1; i > n/2; i--) {
			if (a[i] - a[i-k] != step) ok = false;
		}
		if (ok) break;
	}
	cerr << "step=" << step << ", k=" << k << endl;
	
	function<ll(int)> get = [&](int i) {
		if (i < N) return a[i];
		ll m = (i-N)/k + 1;
		return get(i-m*k) + m*step;
	};

	while (q--) {
		int i; cin >> i;
		cout << get(i-1) << endl;
	}
}
