#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<ll>;
using vii = vector<pair<ll, ll>>;

void solve() {
	int n, q;
	cin >> n >> q;

	vi a(n+1);
	vii qs(q);
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 0; i < q; ++i){
		qs[i].first = i;
		cin >> qs[i].second;
	}
	sort(qs.begin(), qs.end());

	vi ans(q);

	int j = 0;
	while (j < q && qs[j].second <= n) {
		ans[qs[j].first] = a[qs[j].second];
		++j;
	}

	vi s(n);
	for (int i = 1; i <= n; ++i) s[i%n] = a[i];
	int cur = n;
	while (j < q) {
		while (cur < qs[j].second) {
			++cur;
			ll v = a[1] + s[(cur-1)%n];
			for (int k = 2; k <= n; ++k)
				v = min(v, a[k] + s[(cur-k)%n]);
			s[cur%n] = v;
		}
		ans[qs[j].first] = s[qs[j].second%n];
		++j;
	}

	for (int i = 0; i < q; ++i)
		cout << ans[i] << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();

	return 0;
}
