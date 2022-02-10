#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for (auto i=(a); i<(b); ++i)
#define iter(it,c) for (auto it = (c).begin(); it != (c).end(); ++it)
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef long long ll;
const int INF = 2147483647;

void rec(int xlo, int xhi, int ylo, int yhi) {
    cerr << "in the range (" << xlo << "," << ylo << ") - (" << xhi << ", " << yhi << ")" << endl;

    if ((ll)(xhi - xlo) * (yhi - ylo) <= 64) {
        rep(x,xlo,xhi) {
            rep(y,ylo,yhi) {
                cout << x << " " << y << endl;
                ll d;
                if (!(cin >> d)) {
                    return;
                }
                if (d == 0) {
                    return;
                }
            }
        }
    }

    int xd = (xhi - xlo) / 2,
        yd = (yhi - ylo) / 2;

    ll mn = 1000000000000000000LL;
    int mnx, mny;

    rep(xi,0,2) {
        rep(yi,0,2) {
            int x = xlo + xi * xd + xd / 2,
                y = ylo + yi * yd + yd / 2;

            if (x > 1000000 || y > 1000000) {
                continue;
            }

            cout << x << " " << y << endl;
            ll d;
            if (!(cin >> d)) {
                return;
            }

            if (d == 0) {
                return;
            }

            if (d < mn) {
                mn = d;
                mnx = xi;
                mny = yi;
            }
        }
    }

    rec(xlo + mnx * xd, xlo + mnx * xd + xd,
        ylo + mny * yd, ylo + mny * yd + yd);
}

int main() {
    int n;
    cin >> n;

    while (n--) {
        rec(0, 1<<20, 0, 1<<20);
    }

    return 0;
}

