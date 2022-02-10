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

const double EPS = 1e-9;

int main() {
    int n, k;
    cin >> n >> k;
    double x, y;
    cin >> x >> y;
    double ans = (x * n - y * k) / (n - k);
    cout << endl << "              ";
    if (ans < -EPS || ans > 100 + EPS) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << setprecision(12) << ans << endl;
    }
    cout << "                " << endl;

    return 0;
}

