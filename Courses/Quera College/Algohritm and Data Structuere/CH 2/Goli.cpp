#include <bits/stdc++.h>

using namespace std;
int dp[2][1000007];
int main()
{
    int n,q; cin>>n>>q;
    fill_n(dp[0],1000007,0);
    fill_n(dp[1],1000007,-1);
    for (int i = 0; i < n; i++)
    {
        int t;cin>>t;
        dp[0][t]++;
    }
    for (int i = 0; i < q; i++)
    {
        int t; cin>>t; t--;
        int res=0;
        for (int j = t; j> 0; j--)
        {
            if (dp[1][j]!=-1)
            {
                res+=dp[1][j];
                break;
            }
            else
            {
                res+=dp[0][j];
            }
        }
        dp[1][t]=res;
        cout<<res<<'\n';
    }
    
    
}