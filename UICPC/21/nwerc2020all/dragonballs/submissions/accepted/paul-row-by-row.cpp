// More efficient implementation of per.py
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int X = 1e6;

int n;
vector<tuple<int,int,i64>> queries;

i64 query(int x, int y) {
	cout << x << " " << y << endl;
	i64 ans; cin >> ans;
	queries.emplace_back(x, y, ans);
	if (ans == 0) {
		if (--n == 0) exit(0);
	}
	return ans;
}

int main() {
	cin >> n;

	for (int x = 0; x <= X; x++) {
		for (int y = 0; y <= X; y++) {
			bool ok = true;
			for (auto [qx,qy,dist]: queries) {
				int dx = x-qx;
				if (i64(dx)*dx >= dist) continue;
				int dy = ceil(sqrt(dist - i64(dx)*dx)) - 1;
				if (y >= qy-dy && y <= qy+dy) {
					y = max(y, qy+dy);
					ok = false;
				}
			}
			if (ok) query(x,y);
		}
	}
}
