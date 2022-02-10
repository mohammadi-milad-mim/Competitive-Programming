#include <bits/stdc++.h>
using namespace std;

long long n, q, a[3*101*101], k, longest, wanted;

int main() {
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = n+1; i <= 3*n*n; i++) {
		a[i] = LLONG_MAX;
		for (int j = 1; j <= i/2; j++) a[i] = min(a[i], a[j] + a[i-j]);
	}
	for (int i = n*n; i >= 1 && longest == 0; i--) {
		bool same = true;
		wanted = a[3*n*n] - a[3*n*n - i];
		for (int j = 1; j <= 2*n*n && same; j++) if (a[3*n*n - j] - a[3*n*n - j - i] != wanted) same = false;
		if (same) longest = i;
	}
	for (int i = 0; i < q; i++) {
		cin >> k;
		if (k <= 3*n*n) cout << a[k] << endl;
		else {
			long long rounds = (k-n*n)/longest;
			cout << (rounds*wanted + a[k-rounds*longest]) << endl;
		}
	}
}
