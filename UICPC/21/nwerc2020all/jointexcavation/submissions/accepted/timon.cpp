#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

bool dfs(int u, int par, const vvi &G, vi &seen, int &a, int &b, vi &p) {
	--a;
	seen[u] = 1;
	if (a == b) { p.push_back(u); return true; }
	for (int v : G[u]) {
		if (v == par || seen[v] != 0) continue;
		if (dfs(v, u, G, seen, a, b, p)) {
			p.push_back(u);
			return true;
		}
	}
	++b;
	seen[u] = 2;
	if (a == b) { return true; }
	return false;
}

void solve() {
	int n, m;
	cin >> n >> m;
	vvi G(n);
	for (int u, v; m > 0; --m)
		cin >> u >> v, --u, --v, G[u].push_back(v), G[v].push_back(u);

	vi seen(n, 0);
	int a = n, b = 0;
	vi p;
	dfs(0, -1, G, seen, a, b, p);
	cout << p.size() << ' ' << (n-p.size())/2 << endl;
	for (size_t i = 0; i < p.size(); ++i)
		cout << p[i]+1 << " \n"[i+1==p.size()];
	for (int i = 0, x = 0; i < n; ++i)
		if (seen[i] == 0) {
			if (x) cout << ' '; else x = 1;
			cout << i+1;
		}
	cout << endl;
	for (int i = 0, x = 0; i < n; ++i)
		if (seen[i] == 2) {
			if (x) cout << ' '; else x = 1;
			cout << i+1;
		}
	cout << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	solve();
	
	return 0;
}
