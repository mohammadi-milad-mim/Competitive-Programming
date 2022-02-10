#include <bits/stdc++.h>
using namespace std;

long long int n, q, a[101], k;
map<long long int, long long int> dp;

long long explodify(long long int k) {
	if (dp.count(k)) return dp[k];
	if (k <= n) return a[k];
	long long mini = LLONG_MAX;
	for (int i = 1; i < k; i++) {
		mini = min(mini, explodify(i) + explodify(k-i));
	}
	dp[k] = mini;
	return mini;
}

int main() {
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 0; i < q; i++) {
		cin >> k;
		cout << explodify(k) << endl;
	}
}
