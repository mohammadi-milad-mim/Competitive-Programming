#include<algorithm>
#include<cassert>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include <vector>
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

void find_point() {
	int x0 = 0, y0 = 0;

	vector<ll> D(8);
	D[0] = Q(x0, y0);
	if (D[0] == 0)
		return;

	for (int i=0; i < 7; i++) {
		D[i+1] = Q(x0 + i+1, y0);
		if (D[i+1] == 0)
			return;
		ll d1 = D[i], d2 = D[i+1];
		if (abs(d1 - d2) % 2 == 0)
			continue;
		int x1 = x0 + i, x2 = x1 + 1;

		// if (px, py) is closest to D[i], D[i+1] then:
		// d2 - d1 = 2(x0+i) + 1 - 2px
		ll px = x0 + i - (d2 - d1 - 1) / 2;
		if (px < 0 || px > 1000000)
			continue;
		ll py2 = d1 - (x1 - px)*(x1 - px);
		if (!is_square(py2))
			continue;

		ll py_pos = y0 + sqrtl(py2);
		if (0 <= py_pos && py_pos <= 1000000 && Q(px, py_pos) == 0)
			return;

		// ll py_neg = y0 - sqrtl(py2);
		// if (0 <= py_neg && py_neg <= 1000000 && Q(px, py_neg) == 0)
		//	return;
	}

	assert(false);
}

int main() {
	srand(3141592);

	int n;
	cin >> n;
	while (n--) {
		find_point();
	}
	return 0;
}
