#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int X = 1e6;
int n;

i64 query(int x, int y) {
	if (x < 0 || x > X || y < 0 || y > X || n == 0) return 1e16;
	cout << x << " " << y << endl;
	i64 ans; cin >> ans;
	if (ans == 0) n--;
	return ans;
}

int main() {
	mt19937 gen(12345);
	uniform_int_distribution<int> dis(1,X-1);

	cin >> n;
	while (n > 0) {
		int x = dis(gen), y = dis(gen);
		i64 r = query(x,y);
		
		set<pair<i64,i64>> candidates;
		i64 dx = sqrt(r) + 1;
		for (i64 dy = 0; dy*dy <= r; dy++) {
			while (dx*dx + dy*dy > r) dx--;
			if (dx*dx + dy*dy == r) {
				candidates.emplace(x+dx, y+dy);
				candidates.emplace(x+dx, y-dy);
				candidates.emplace(x-dx, y+dy);
				candidates.emplace(x-dx, y-dy);
			}
		}
		if (candidates.size() > 100) continue;

		for (auto [nx,ny]: candidates) {
			if (query(nx,ny) == 0) break;
		}
	}
}
