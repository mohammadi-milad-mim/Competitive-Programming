#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;

	int ax, ay, bx, by;
	cin >> ax >> ay >> bx >> by;

	set<pair<int,int>> moves;
	for (int i = 0; i < n; i++) {
		int dx, dy;
		cin >> dx >> dy;
		moves.emplace(dx,dy);
	}
	moves.emplace(0,0);

	auto reach_in_two = [&](int sx, int sy, int tx, int ty) {
		for (auto [dx,dy]: moves) {
			int mx = sx+dx, my = sy+dy;
			if (mx < 1 || mx > n || my < 1 || my > n) continue;
			if (moves.count({tx-mx, ty-my})) return true;
		}
		return false;
	};

	if (reach_in_two(ax, ay, bx, by)) {
		cout << "Alice wins" << endl;
		return 0;
	}

	if (n == 2) {
		for (int tx: {1,2}) for (int ty: {1,2}) {
			if (!reach_in_two(bx, by, tx, ty)) {
				cout << "tie " << tx << " " << ty << endl;
				return 0;
			}
		}
		cout << "Bob wins" << endl;
		return 0;
	}
	
	srand(123);
	int tx = bx, ty = by;
	while (reach_in_two(bx, by, tx, ty)) {
		tx = 1 + rand() % n;
		ty = 1 + rand() % n;
	}
	
	cout << "tie " << tx << " " << ty << endl;
}
