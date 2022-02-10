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

double expected;
vector<tuple<int,double,int> > tricks;
int n, r, m;
map<ii,double> mem;

double dp(int at, int t) {
    if (t >= r) {
        return t+expected;
    }
    if (at == (int)tricks.size()) {
        return t;
    }

    ii st(at,t);
    if (mem.find(st) != mem.end()) {
        return mem[st];
    }

    auto [curt, prob, penalty] = tricks[at];
    int nxtt = at + 1 < tricks.size() ? get<0>(tricks[at+1]) : n;
    int walk = (nxtt - curt);

    double ans = min(t+expected,
            prob * (dp(at+1, t + walk)) +
            (1 - prob) * min(t+expected, dp(at+1, t + walk + penalty)));
    return mem[st] = ans;
}

int main() {
    srand(time(NULL));
    cin >> n >> r >> m;

    rep(i,0,m) {
        int t, add;
        double p;
        cin >> t >> p >> add;
        tricks.emplace_back(t, p, add);
    }

    sort(tricks.begin(), tricks.end());

    double lo = 0.0,
           hi = 1e9;
    rep(it,0,100) {
        expected = (lo+hi)/2;
        mem.clear();
        double t = dp(0,get<0>(tricks[0]));
        if (t > expected) {
            lo = expected;
        } else {
            hi = expected;
        }
    }

    cout << setprecision(12) << lo << endl;
    return 0;
}

