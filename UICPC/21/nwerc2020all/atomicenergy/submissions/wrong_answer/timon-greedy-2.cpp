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

	vi aa(n);
	vector<val> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i].a, a[i].i = i+1, aa[i] = a[i].a;
	sort(a.begin(), a.end());

	while (q--) {
		int k;
		cin >> k;

		ll v = 0LL;
		for (int i = 0; i < n && k > n; ++i) {
			v += a[i].a * ((k-n) / a[i].i);
			k = (k-n) % a[i].i + n;
		}
		v += aa[k-1];
		cout << v << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();

	return 0;
}
