#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(void) {
    int n;
    scanf("%d", &n);
    vector<ll> a(n), a_sum(n+1);
    for (ll &x: a) scanf("%lld", &x);
    partial_sum(a.begin(), a.end(), a_sum.begin()+1);

    vector<int> prev_neg(n+1, -1), prev_pos(n+1, -1);
    for (int i = 1; i <= n; ++i) {
        int j = i-1;
        if (a[j] == 0 && (!j || a[j-1] == 0))
            j = prev_neg[j];
        else {
            while (j >= 0 && a_sum[i] - a_sum[j] >= i - j)
                j = prev_neg[j];
        }
        prev_neg[i] = j;
        
        j = i-1;
        while (j >= 0 && a_sum[i] - a_sum[j] < i - j)
            j = prev_pos[j];
        prev_pos[i] = j;
    }

    vector<ll> opt(n+1);
    for (int i = 1; i <= n; ++i) {
        opt[i] = max(a_sum[i] - 1, 0LL);
        if (a[i-1] == 0) opt[i] = min(opt[i], opt[i-1]);
        int j = prev_pos[i];
        while (j >= 0) {
            if (a_sum[i] - a_sum[j] < i-j) {
                j += (i - j) - (a_sum[i] - a_sum[j]);
                assert(a_sum[i] - a_sum[j] == i-j);
                opt[i] = min(opt[i], opt[j] + i-j-1);
                break;
            }
            opt[i] = min(opt[i], opt[j] + 2*(a_sum[i]-a_sum[j]) - (i-j) - 1);
            j = prev_neg[j];
        }
    }
    ll ans = 1LL<<60;
    for (int i = 1; i <= n; ++i)
        ans = min(ans, opt[i] + max(a_sum[n] - a_sum[i] - 1, 0LL));
    printf("%lld\n", ans);
    return 0;
}
