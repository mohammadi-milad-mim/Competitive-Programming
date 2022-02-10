#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool isp[1000];

const ll LIMIT = 1000 * 1000;

ll D(ll x, ll y, ll a, ll b) {
	return (x-a)*(x-a) + (y-b)*(y-b);
}

int main(int argc, char **argv) {
	assert(argc == 4); // ./a.out x y {seed}
	int x = atoi(argv[1]), y = atoi(argv[2]);
	srand(atoi(argv[3]));

	ll max_norm = max({
		D(x,y,0,0),
		D(x,y,0,LIMIT),
		D(x,y,LIMIT,LIMIT),
		D(x,y,LIMIT,LIMIT)
	});

	// small prime sieve:
	fill_n(isp, 1000, true);
	for (int p = 2; p < 1000; p++) {
		if (!isp[p]) continue;
		for (int n = p*p; n < 1000; n += p)
			isp[n] = false;
	}

	// take a product of primes 1 modulo 4
	ll prod = 1LL;
	for (int p = 5; p < 1000; p += 4) {
		if (isp[p] && prod * p <= max_norm) {
			prod *= p;
		}
	}

	while (prod * 25 <= max_norm)
		prod *= 25;

	set<pair<int,int>> points;

	for (ll x1 = 0; x1 <= LIMIT; x1++) {
		ll ysq = prod - (x1-x)*(x1-x);
		ll dy = sqrtl(ysq);
		if (dy*dy == ysq) {
			ll y1 = y - dy, y2 = y + dy;
			if (0 <= y1 && y1 <= LIMIT) points.emplace(x1, y1);
			if (0 <= y2 && y2 <= LIMIT) points.emplace(x1, y2);
		}
	}

	vector<pair<int,int>> ps(begin(points), end(points));
	random_shuffle(begin(ps), end(ps));

	cout << 7 << endl;
	for (int i=0; i<7; i++) {
		assert(D(x, y, ps[i].first, ps[i].second) == prod);
		cout << ps[i].first << " " << ps[i].second << endl;
	}
	return 0;
}
