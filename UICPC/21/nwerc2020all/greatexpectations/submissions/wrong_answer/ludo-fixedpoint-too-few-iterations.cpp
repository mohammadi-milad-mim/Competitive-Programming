#include<algorithm>
#include<cassert>
#include<climits>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<iostream>

using namespace std;
typedef long long ll;
typedef double ld;

int n, r, m, T[52], d[52];
ld p[52];

// E[i][t] = expected time it takes to have performed tricks up to i (incl.)
//           with exactly t seconds lost due to delays.
ld E[52][5001];

double traceback(ld ans) {
	for (int t=0; t<r; t++)
		E[m+1][t] = T[m+1] - T[m];

	// O(m (r-n)) < 250'000
	for (int i = m; i >= 1; i--) {
		int dt = T[i] - T[i-1];
		for (int t = 0; t < r - d[i]; t++)
			E[i][t] = dt + p[i] * E[i+1][t] + (1 - p[i]) * min(ans, d[i] + E[i+1][t + d[i]]);
		for (int t = r-d[i]; t < r; t++)
			E[i][t] = dt + p[i] * E[i+1][t] + (1 - p[i]) * ans;
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
	T[m+1] = n;

	// we are only interested in the max. allowed trick delay
	r -= n;

	ld res = n;
	for (int i=1; i <= m; i++)
		res += (1 - p[i]) * d[i];

	// did not work as good:
	//for (int i = 1; i <= m; i++) res += (T[i] + d[i]) / p[i] - d[i];

	// when it is hot, make big jumps to fixed point,
	// and when cooling down, make the steps smaller...
	for (int temp = 1024; temp >= 1; temp /= 2) {
		for (int rep = 500; rep--; ) {
			ld last_res = res, nres = traceback(res);
			// res = traceback(res);
			res += (nres - res) * temp;
			if (abs(last_res - res) < 1e-8)
				break;
		}
	}
	cout << res << endl;
	return 0;
}
