#include<algorithm>
#include<iostream>
#include<set>
using namespace std;

const int MAXN = 100 * 1000;
int n, x[MAXN], v[MAXN];
int nxt[MAXN], prv[MAXN]; // skip list
bool alive[MAXN];

struct frac {
	int num, den;
	frac(int _n, int _d) : num(_n), den(_d) {}
};

bool operator<(frac a, frac b) {
	return (long long)(a.num) * b.den < (long long)(a.den) * b.num;
}
bool operator==(frac a, frac b) {
	return a.num * b.den == a.den * b.num;
}

// when drone i is at x_i travelling with speed v_i (i=1,2),
// and x_1 < x_2 and v_1 > v_2 then there is a collision at time
// (x_2 - x_1) / (v1 - v_2).

set<pair<frac,int>> events;

int main() {
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> x[i] >> v[i];
		prv[i] = i-1;
		nxt[i] = i+1;
		alive[i] = true;
	}

	for (int i=0; i+1 < n; i++) {
		if (v[i] <= v[i+1])
			continue;
		events.emplace(frac(x[i+1] - x[i], v[i] - v[i+1]), i);
	}

	while (!events.empty()) {
		frac t = events.begin()->first;
		int L = events.begin()->second, R = nxt[L];
		events.erase(events.begin());
		// L and R collide as first ones.
		alive[L] = alive[R] = false;

		int pL = prv[L], nR = nxt[R];
		if (pL >= 0)
			nxt[pL] = nR;
		if (nR < n)
			prv[nR] = pL;

		// check if we need to remove events:
		if (pL >= 0 && v[pL] > v[L])
			events.erase(make_pair(frac(x[L] - x[pL], v[pL] - v[L]), pL));
		if (nR < n && v[R] > v[nR])
			events.erase(make_pair(frac(x[nR] - x[R], v[R] - v[nR]), R));

		// check if we need to add a new event:
		if (pL >= 0 && nR < n && v[pL] > v[nR]) {
			events.emplace(frac(x[nR] - x[pL], v[pL] - v[nR]), pL);
		}
	}

	int cnt = 0;
	for (int i=0; i<n; i++)
		cnt += alive[i];

	cout << cnt << endl;
	for (int i=0; i<n; i++) {
		if (alive[i]) {
			cout << (i+1) << (--cnt ? " " : "\n");
		}
	}

	return 0;
}
