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
		
		i64 dx = sqrt(r) + 1;
		for (i64 dy = 0; dy*dy <= r; dy++) {
			while (dx*dx + dy*dy > r) dx--;
			if (dx*dx + dy*dy == r) {
				if (query(x+dx, y+dy) == 0) break;
				if (query(x+dx, y-dy) == 0) break;
				if (query(x-dx, y+dy) == 0) break;
				if (query(x-dx, y-dy) == 0) break;
			}
		}
	}
}
