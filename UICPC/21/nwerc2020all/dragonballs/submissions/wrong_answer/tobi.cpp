#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int numBalls;
ll dirs[][2] = {{-1, 0}, {0, -1}, {+1, 0}, {0, +1}};

ll guess(ll x, ll y) {
	cout << x << " " << y << endl << flush;
	ll dist;
	cin >> dist;
	return dist;
}

void findBall(ll x, ll y, ll lastMove) {
	ll best = guess(x, y);
	if (best == 0LL) return;
	while (lastMove >= 1) {
		for (int i = 0; i < 4; i++) {
			ll newX = x + dirs[i][0]*lastMove, newY = y + dirs[i][1]*lastMove;
			if (newX >= 0 && newY >= 0 && newX <= 1000000 && newY <= 1000000) {
				ll cur = guess(newX, newY);
				if (cur == 0LL) return;
				if (cur < best) {
					findBall(newX, newY, lastMove);
					return;
				}
			}
		}
		lastMove /= 2;
	}
}

int main() {
	cin >> numBalls;
	for (int i = 0; i < numBalls; i++) findBall(1000000/2, 1000000/2, 1000000/2-1);
}
