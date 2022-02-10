#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int dp[n];
    for (int i=0; i<n; i++){
        cin>>dp[i];
    }
    int cdp[n];
    copy(dp, dp+n, cdp);
    sort(dp, dp+n);
    int tem = dp[0];
    int ma = 0;
    for (int i=0; i<n-1; i++){
        if (dp[i]!=dp[i+1]){
            if ((i!=0) && (dp[i]!=dp[i-1])){
                tem = dp[i];
                if (tem>ma) ma=tem;
            }
            else if(i==0){
                tem = dp[i];
                if (tem>ma) ma=tem;
            }
        }
    }
    if (dp[n-1]!=dp[n-2]) ma=dp[n-1];
    if (ma){
        auto itr = find(cdp, cdp + n, ma);
        cout<<distance(cdp, itr)+1;
    }
    else cout<<"none";
}