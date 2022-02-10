#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<ll>;

struct val {
	ll a, i;
	bool operator<(const val &o) const {
		return a*o.i < o.a*i;
	}
};

void solve() {
	int n, q;
	cin >> n >> q;

	vi a(3*n+1);
	ll b = -1LL, bv = 1LL;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (b<0 || a[i] * bv < b * i)
			b = a[i], bv = i;
	}
	for (int i = n+1; i <= 3*n; ++i) {
		a[i] = a[i-1] + a[1];
		for (int j = 2; j <= n && i-j >= 1; ++j)
			a[i] = min(a[i], a[j] + a[i-j]);
	}

	while (q--) {
		int k;
		cin >> k;

		ll m = max(k - 3*n + bv - 1, 0LL) / bv;
		k -= m*bv;
		cout << a[k] + m*b << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();

	return 0;
}
