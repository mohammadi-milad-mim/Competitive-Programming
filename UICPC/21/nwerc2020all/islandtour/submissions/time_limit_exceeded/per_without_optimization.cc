#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    scanf("%d", &n);
    vector<ll> d(n);
    vector<vector<ll>> t(3, vector<ll>(n));
    vector<vector<vector<pair<ll,ll>>>> ivals(3);
    for (ll &x: d) scanf("%lld", &x);
    for (int i = 0; i < 3; ++i) {
        for (ll &x: t[i]) scanf("%lld", &x);

        ivals[i].resize(n);
        for (int a = 0; a < n; ++a) {
            ll curt = 0;
            ivals[i][a].resize(n);
            for (int b = 0; b < n; ++b) {
                ivals[i][a][(a+b)%n] = make_pair(curt, curt + t[i][(a+b)%n]);
                curt += t[i][(a+b)%n] + d[(a+b)%n];
            }
        }
    }

    auto disjoint = [&](const pair<ll, ll> &I, const pair<ll, ll> &J) {
        return I.second <= J.first || J.second <= I.first;
    };
    auto ok = [&](int i, int s, int t) {
        for (int x = 0; x < n; ++x)
            if (!disjoint(ivals[i][s][x], ivals[(i+1)%3][t][x]))
                return false;
        return true;
    };

    for (int i1 = 0; i1 < n; ++i1)
        for (int i2 = 0; i2 < n; ++i2)
            for (int i3 = 0; i3 < n; ++i3)
                if (ok(0, i1, i2) && ok(1, i2, i3) && ok(2, i3, i1)) {
                    printf("%d %d %d\n", i1+1, i2+1, i3+1);
                    return 0;
                }
    printf("impossible\n");
}
                                      
                                      
