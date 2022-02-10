#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;

void solve() {
	int n;
	cin >> n;

	vi a(n);
	for (ll &v : a) cin >> v;
	sort(a.begin(), a.end());

	vi ans;
	int l = 0, r = n-1;
	while (l <= r) {
		ans.push_back(a[l++]);
		if (l < r)
			ans.push_back(a[r--]);
	}
	reverse(ans.begin(), ans.end());
	for (int i = 0; i < n; ++i)
		cout << ans[i] << " \n"[i+1==n];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	solve();
	
	return 0;
}
