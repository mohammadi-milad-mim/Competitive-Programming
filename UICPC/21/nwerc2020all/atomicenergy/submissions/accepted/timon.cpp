#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<ll>;

void solve() {
	int n, q;
	cin >> n >> q;

	vi a(n+1);
	for (int i = 1; i <= n; ++i) cin >> a[i];

	int m = 1;
	for (int i = 2; i <= n; ++i)
		if (a[i] * m < a[m] * i)
			m = i;

	a.resize(n*(m+1) + 1);
	for (int j = n+1; j <= n*(m+1); ++j) {
		a[j] = a[1] + a[j-1];
		for (int i = 2; i <= n; ++i)
			a[j] = min(a[j], a[j-i] + a[i]);
	}

	while (q--) {
		int k;
		cin >> k;
		if (k <= n * (m+1))
			cout << a[k] << '\n';
		else {
			int i = (k-n+m-1)/m - n;
			cout << a[k-i*m] + i*a[m] << '\n';
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();

	return 0;
}
