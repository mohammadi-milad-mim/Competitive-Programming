#include<algorithm>
#include<cassert>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<set>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
#define x first
#define y second

const int DP_SIZE = 100 * 1000; // n*n?
ll a[101], DP[DP_SIZE];

int main() {
	int n, q;
	cin >> n >> q;
	for (int i=1; i <= n; i++)
		cin >> a[i];

	int best_ratio = 1;
	for (int i = 2; i <= n; i++) {
		if (a[i] * best_ratio < a[best_ratio] * i)
			best_ratio = i;
	}

	DP[0] = 0;
	for (int i = 1; i <= n; i++)
		DP[i] = a[i];
	for (int i = n+1; i < DP_SIZE; i++) {
		DP[i] = DP[i-1] + a[1];
		for (int take = 2; take <= n; take++)
			DP[i] = min(DP[i], DP[i - take] + a[take]);
	}

	while (q--) {
		int k;
		cin >> k;

		if (k < DP_SIZE) {
			cout << DP[k] << endl;
		} else {
			int rem = DP_SIZE + ((k-DP_SIZE) % best_ratio) - best_ratio;
			assert(rem < DP_SIZE && k % best_ratio == rem % best_ratio);
			ll Q = (k-rem) / best_ratio;

			cout << (a[best_ratio] * Q + DP[rem]) << endl;
		}
	}

	return 0;
}
