#include <bits/stdc++.h>
using namespace std;

long long n, d[405], t, start[3][405], ende[3][405], dp[3][3][405][405];

bool collide(int p1, int p2, int from1, int from2) {
	if (dp[p1][p2][from1][from2]) return dp[p1][p2][from1][from2] > 0;
	bool caught = false;
	long long deltaP1 = -start[p1][from1], deltaP2 = -start[p2][from2];
	for (int i = 0; i < n; i++) {
		long long wrapP1 = i < from1 ? (ende[p1][n-1] + d[n-1]) : 0;
		long long wrapP2 = i < from2 ? (ende[p2][n-1] + d[n-1]) : 0;
		if (start[p1][i] + wrapP1 + deltaP1 <= ende[p2][i] + wrapP2 + deltaP2
				&& start[p2][i] + wrapP2 + deltaP2 <= ende[p1][i] + wrapP1 + deltaP1) {
			caught = true;
			break;
		}
	}
	if (caught) dp[p1][p2][from1][from2] = 1;
	else dp[p1][p2][from1][from2] -= 1;
	return dp[p1][p2][from1][from2] > 0;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> d[i];
	for (int p = 0; p < 3; p++) for (int i = 0; i < n; i++) {
		cin >> t;
		start[p][i] = i == 0 ? 0 : ende[p][i-1] + d[i];
		ende[p][i] = start[p][i] + t;
	}

	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
		if (i == j || collide(0, 1, i, j)) continue;
		for (int k = 0; k < n; k++) {
			if (i == k || j == k || collide(0, 2, i, k) || collide(1, 2, j, k)) continue;
			cout << (i+1) << " " << (j+1) << " " << (k+1) << endl;
			return 0;
		}
	}
	cout << "impossible" << endl;
}
