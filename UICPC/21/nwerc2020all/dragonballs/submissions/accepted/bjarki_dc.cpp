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

#define SQ(x) ((x)*(x))
#define DIST(x0,y0, x1,y1) (SQ((x0)-(x1))+SQ((y0)-(y1)))

bool any_inside(ll x0, ll x1, ll y0, ll y1, bool &found) {
    found = false;
    ll xmid = (x0+x1)/2,
       ymid = (y0+y1)/2,
       d;
    cout << xmid << " " << ymid << endl;
    if (!(cin >> d)) {
        exit(0);
    }
    if (d == 0) {
        found = true;
        return true;
    }

    ll mxd = 0;
    mxd = max(mxd, DIST(x0, y0, xmid, ymid));
    mxd = max(mxd, DIST(x0, y1, xmid, ymid));
    mxd = max(mxd, DIST(x1, y1, xmid, ymid));
    mxd = max(mxd, DIST(x1, y0, xmid, ymid));

    return d <= mxd;
}

bool rec(ll x0, ll x1, ll y0, ll y1) {
    bool found;
    if (!any_inside(x0, x1, y0, y1, found)) {
        return false;
    }
    if (found) {
        return true;
    }

    ll xmid = (x0+x1)/2,
       ymid = (y0+y1)/2;
    vector<tuple<ll,ll,ll,ll> > areas = {
        {x0, xmid, y0, ymid},
        {x0, xmid, ymid+1, y1},
        {xmid+1, x1, y0, ymid},
        {xmid+1, x1, ymid+1, y1},
    };

    random_shuffle(areas.begin(), areas.end());

    for (auto [x0,x1,y0,y1] : areas) {
        if (x0 <= x1 && y0 <= y1) {
            if (rec(x0,x1,y0,y1)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    srand(time(NULL));

    int n;
    cin >> n;

    while (n--) {
        assert(rec(0, 1000000, 0, 1000000));
    }

    return 0;
}

