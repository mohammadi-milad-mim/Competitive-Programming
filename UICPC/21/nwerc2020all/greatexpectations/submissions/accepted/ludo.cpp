#include<algorithm>
#include<cassert>
#include<climits>
#include<iostream>
using namespace std;
typedef long long ll;
typedef long double ld;

int n, r, m, T[52], d[52];
ld p[52];

// E[i][t] = expected time it takes to have performed tricks up to i (incl.)
//           with exactly t seconds lost due to delays.
ld E[52][5001];

ld traceback(ld ans) {
	for (int t=0; t<r; t++)
		E[m+1][t] = n - T[m];

	// O(m (r-n)) < 250'000
	for (int i = m; i >= 1; i--) {
		int dt = T[i] - T[i-1];
		for (int t = 0; t < r; t++) {
			if (t + d[i] < r)
				E[i][t] = dt + p[i] * E[i+1][t] + (1 - p[i]) * min(ans, d[i] + E[i+1][t + d[i]]);
			else
				E[i][t] = dt + p[i] * E[i+1][t] + (1 - p[i]) * ans;
		}
	}
	return E[1][0];
}

int main() {
	(cout << fixed).precision(7);

	cin >> n >> r >> m;
	for (int i=1; i <= m; i++) {
		cin >> T[i] >> p[i] >> d[i];
	}

	T[0] = 0;
	r -= n; // we are only interested in the max. allowed trick delay

	ld lo = 0, hi = 50'000 * 5000;

	assert(traceback(lo) > lo);
	assert(traceback(hi) <= hi);
	while (hi - lo > 1e-10 && (hi - lo) / hi > 1e-10) {
		ld mid = (lo+hi)*0.5;
		if (traceback(mid) > mid)
			lo = mid;
		else
			hi = mid;
	}
	cout << (lo+hi)*0.5 << endl;
	return 0;
}
