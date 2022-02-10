#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(void) {
    int n;
    scanf("%d", &n);
    vector<ll> a(n), a_sum(n+1);
    for (ll &x: a) scanf("%lld", &x);
    partial_sum(a.begin(), a.end(), a_sum.begin()+1);

    vector<ll> opt(n+1);
    for (int i = 1; i <= n; ++i) {
        opt[i] = 1LL<<60;
        for (int j = 0; j < i; ++j) {
            ll width = i-j, mass = a_sum[i]-a_sum[j];
            if (i == n || j == 0) width = mass;
            ll c = 0;
            if (mass) c = 2*mass - min(width, mass) - 1;
            opt[i] = min(opt[i], opt[j] + c);
        }
    }
    printf("%lld\n", opt[n]);
    return 0;
}
