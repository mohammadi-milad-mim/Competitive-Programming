#include <bits/stdc++.h>
using namespace std;

long long n, q, a[101], k;
map<long long, long long> dp;

long long explodify(long long int k) {
	if (k <= n) return a[k];
	long long mini = LLONG_MAX, delta = (k-n*2);
	if (k <= 2*n) {
		if (dp.count(k)) return dp[k];
		for (int i = 1; i < k; i++) {
			mini = min(mini, explodify(i) + explodify(k-i));
		}
		dp[k] = mini;
		return mini;
	}
	for (int i = 1; i <= n; i++) {
		long long rounds = (delta+i-1)/i;
		if (k - rounds*i < 1) continue;
		mini = min(mini, rounds*a[i] + explodify(k - rounds*i));
	}
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
