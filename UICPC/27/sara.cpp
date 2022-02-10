#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ld;
// cout << setprecision(3) << fixed << doubllle;
// sort(arr, arr + n, greater<int>());
//c = ::tolower(c);
//for (int i = 0; i < s.size(); i++) {
//s[i] = tolower(s[i]);
//multiset<lli, greater<lli>> mset;
//int dx[4]={0,-1,0,1};
//int dy[4]={-1,0,1,0};
//M_PI >>Pi
ld dp[(1<<16)+5][1000+5];
int cost[1000+5];
ld prb[1000+5];
int n, c, mymoney;
ld ans=0;
ld cdp(int mask, int money, int count)
{
    if(count == c-1)
    {
        return 1;
    }
    if(dp[mask][money] != -1)
    {
        return dp[mask][money];
    }
    
    ld ans_now=0;
    for(int i=0; i<n; i++)
    {
        if(!(mask & (1<<i)))
        {
            if(money >= cost[i])
            {
                ld temp1 = prb[i];
                ld temp2 = 1-prb[i];
                temp1 *= cdp(mask|(1<<i), money-cost[i], count+1);
                temp2 *= cdp(mask|(1<<i), money-cost[i], count);
                if((temp1+temp2)-ans_now >= 0.000001)
                {
                    ans_now = temp1+temp2;
                }
            }
        }
    }
    return dp[mask][money] = ans_now;

}
int main()
{
    int t; cin>>t;
    while(t--)
    {
        cin>>n>>c>>mymoney;
        for(int i=0; i<n; i++)
        {
            int f;
            cin>>cost[i]>>f;
            prb[i] = (ld)f/(ld)100;
        }
        for(int i=0; i<(1<<16)+5; i++)
        {
            for (int j = 0; j <= c; j++)
            {
                dp[i][j] = -1;
            }
        }
        cdp(0, mymoney, c);
        cout << setprecision(6) << fixed << dp[0][mymoney] << endl;
    }
}