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

const int max_m = 50,
          max_r = 5 * 1000;
bool comp[max_m+1][max_r+1];
double mem[max_m+1][max_r+1];

double dp(int at, int t) {
    if (t >= r) {
        return t+expected;
    }
    if (at == (int)tricks.size()) {
        return t;
    }

    if (comp[at][t]) {
        return mem[at][t];
    }

    auto [curt, prob, penalty] = tricks[at];
    int nxtt = at + 1 < tricks.size() ? get<0>(tricks[at+1]) : n;
    int walk = (nxtt - curt);

    double ans = min(t+expected,
            prob * (dp(at+1, t + walk)) +
            (1 - prob) * min(t+expected, dp(at+1, t + walk + penalty)));
    comp[at][t] = true;
    return mem[at][t] = ans;
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

    expected = 0;
    while (true) {
        memset(comp,0,sizeof(comp));
        double expected2 = dp(0,get<0>(tricks[0]));
        if (abs(expected-expected2) < 1e-7) {
            break;
        }
        expected = expected2;
    }

    cout << setprecision(12) << expected << endl;
    return 0;
}

