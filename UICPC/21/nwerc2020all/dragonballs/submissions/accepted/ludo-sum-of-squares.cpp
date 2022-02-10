#include<algorithm>
#include<cassert>
#include<cmath>
#include<cstdlib>
#include<iostream>
using namespace std;
typedef long long ll;

ll Q(ll x, ll y) {
	cout << x << " " << y << endl;
	cout.flush();
	ll d;
	cin >> d;
	return d;
}

bool is_square(ll n) {
	ll sn = (ll) sqrtl(n);
	return sn * sn == n;
}

const ll MAXCOORD = 1000 * 1000;

int main() {
	int n;
	cin >> n;
	while (n--) {
		ll d = Q(0, 0);
		if (d == 0) continue;
		ll x=0;
		for (; x*x <= d; x++) {
			ll y2 = d - x*x;
			if (!is_square(y2))
				continue;
			ll y = sqrtl(y2);
			if (x <= MAXCOORD && y <= MAXCOORD && Q(x, y) == 0)
				break;
		}
		assert(x*x <= d);
	}
}
