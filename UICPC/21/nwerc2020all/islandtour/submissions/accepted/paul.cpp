#include <bits/stdc++.h>
using namespace std;

#define FOR(i,n) for (int i = 0; i < n; i++)

int main() {
	int n; cin >> n;

	int dist[n];
	FOR(i,n) cin >> dist[i];
	
	int stay[3][n];
	FOR(a,3) FOR(i,n) cin >> stay[a][i];

	// arrive[a][i][j] = time when person a first arrives at location j
	//                   when starting from location i at time 0.
	int arrive[3][n][n];
	FOR(a,3) FOR(i,n) {
		auto &dp = arrive[a][i];
		dp[i] = 0;
		for (int j = i; (j+1)%n != i; j = (j+1)%n) {
			dp[(j+1)%n] = dp[j] + stay[a][j] + dist[j];
		}
	}

	// can[a][b][i][j] <-> person a starting at i and person b starting at j never meet
	bool can[3][3][n][n];
	FOR(a,3) FOR(b,3) if (a < b) {
		FOR(i,n) FOR(j,n) {
			can[a][b][i][j] = 1;
			FOR(k,n) {
				bool ok = arrive[a][i][k]+stay[a][k] <= arrive[b][j][k] ||
					      arrive[b][j][k]+stay[b][k] <= arrive[a][i][k];
				if (!ok) can[a][b][i][j] = 0;
			}			
		}
	}
	
	FOR(i,n) FOR(j,n) FOR(k,n) {
		if (can[0][1][i][j] && can[0][2][i][k] && can[1][2][j][k]) {
			cout << i+1 << " " << j+1 << " " << k+1 << endl;
			return 0;
		}
	}
	cout << "impossible" << endl;
}
