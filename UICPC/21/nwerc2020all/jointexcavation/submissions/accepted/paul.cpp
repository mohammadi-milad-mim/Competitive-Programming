#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> adj(n);
	while (m--) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	vector<int> col(n), cnt(3), stk;
	cnt[0] = n;

	auto print_and_exit = [&]() {
		cout << cnt[1] << " " << cnt[0] << endl;
		for (int i: stk) cout << i+1 << " ";
		cout << endl;
		for (int c: {0,2}) {
			for (int i = 0; i < n; i++) {
				if (col[i] == c) cout << i+1 << " ";
			}
			cout << endl;
		}
		exit(0);
	};

	auto recolour = [&](int i, int c) {
		cnt[col[i]]--;
		col[i] = c;
		cnt[col[i]]++;
		if (cnt[0] == cnt[2]) print_and_exit();
	};

	function<void(int)> dfs = [&](int i) {
		stk.push_back(i);
		recolour(i,1);
		for (int j: adj[i]) if (col[j] == 0) dfs(j);
		stk.pop_back();
		recolour(i,2);
	};
	
	dfs(0);
	cout << "impossible" << endl;
}
