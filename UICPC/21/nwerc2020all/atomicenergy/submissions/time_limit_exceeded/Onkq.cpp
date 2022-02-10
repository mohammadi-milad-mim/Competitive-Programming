#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<ll>;

void solve() {
	int n, q;
	cin >> n >> q;

	vi a(n+1);
	for (int i = 1; i <= n; ++i) cin >> a[i];
	while (q--) {
		int k;
		cin >> k;
		
		vi s(n);
		for (int i = 1; i <= n; ++i) s[i%n] = a[i];

		for (int j = n+1; j <= k; ++j) {
			ll v = a[1] + s[(j-1)%n];
			for (int k = 2; k <= n; ++k)
				v = min(v, a[k] + s[(j-k)%n]);
			s[j%n] = v;
		}
		cout << s[k%n] << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();

	return 0;
}
