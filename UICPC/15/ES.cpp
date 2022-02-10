#include<bits/stdc++.h>
using namespace std;
# define inf 0x3f3f3f3f
# define ll_inf (1ll<<60)
# define ll long long
# define lson l,mid,rt<<1
# define rson mid+1,r,rt<<1|1
const ll maxn = 3e5+100;
const ll mod = 1e9+7;
ll dp[maxn];
ll pre[maxn];
ll num[maxn];
int main()
{
    int n;
    scanf("%d",&n);
    ll tmp;
    for(int i=1; i<=n; i++)
    {
        scanf("%lld",&tmp);
        pre[i]=pre[i-1]+tmp;
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=i-1; j>=0; j--)
        {
            if(pre[i]-pre[j]>=dp[j]) // After finding it, you can stop; assuming the optimal solution, then the back of this point must also match, because it is more
            {
                dp[i]=pre[i]-pre[j];
                num[i]=num[j]+1;
                break;
            }
        }
    }
    printf("%lld\n",num[n]);
    return 0;
}