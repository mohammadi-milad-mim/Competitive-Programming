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

const int ALICE = 1, BOB = -1, TIE = 0;

istream& operator>>(istream &in, ii &pr) {
	return in >> pr.x >> pr.y;
}

int tie_x, tie_y;

int solve() {
	int n;
	cin >> n;
	ii alice, bob;
	cin >> alice >> bob;
	alice.x--; alice.y--;
	bob.x--; bob.y--;

	vector<ii> moves(n);
	set<ii> movesS;
	for (ii &mv : moves) {
		cin >> mv;
		movesS.insert(mv);
	}

	for (ii mv : moves) {
		int newx = alice.x + mv.x, newy = alice.y + mv.y;
		if (newx < 0 || newx >= n || newy < 0 || newy >= n)
			continue;
		int nx = bob.x - newx, ny = bob.y - newy;
		if (nx == 0 && ny == 0)
			return ALICE;
		if (movesS.find(ii(nx, ny)) != movesS.end())
			return ALICE;
	}

	if (n < 100) {
		vector<vector<bool>> taken(n, vector<bool>(n, false));
		taken[bob.x][bob.y] = true;
		for (ii mv1 : moves) {
			int newx = bob.x + mv1.x, newy = bob.y + mv1.y;
			if (newx < 0 || newx >= n || newy < 0 || newy >= n)
				continue;
			taken[newx][newy] = true;
			for (ii mv2 : moves) {
				int dx = newx + mv2.x;
				int dy = newy + mv2.y;
				if (0 <= dx && dx < n && 0 <= dy && dy < n)
					taken[dx][dy] = true;
			}
		}
		for (int x = 0; x < n; x++) {
			for (int y = 0; y < n; y++) {
				if (!taken[x][y]) {
					tie_x = x;
					tie_y = y;
					return TIE;
				}
			}
		}
		return BOB;
	} else {
		for (int attempts = 100; attempts--; ) {
			int rx = rand() % n, ry = rand() % n;
			bool valid = true;
			for (ii mv : moves) {
				int newx = bob.x + mv.x, newy = bob.y + mv.y;
				if (newx < 0 || newx >= n || newy < 0 || newy >= n)
					continue;
				int nx = rx - newx, ny = ry - newy;
				if (movesS.find(ii(nx, ny)) != movesS.end()) {
					valid = false;
					break;
				}
			}
			if (valid) {
				tie_x = rx;
				tie_y = ry;
				return TIE;
			}
		}
		return BOB;
	}
}

int main() {
	srand(3141592);

	int ans = solve();
	if (ans == ALICE) cout << "Alice wins";
	else if (ans == BOB) cout << "Bob wins";
	else cout << "tie " << (tie_x+1) << " " << (tie_y+1);
	cout << endl;
	return 0;
}
