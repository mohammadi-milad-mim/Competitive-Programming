#include <bits/stdc++.h>

using namespace std;

int main(){
    int r,n;
    cin>>r>>n;
    int dp[r+1];
    for (int i=0; i<r+1; i++) dp[i]=0;
    int t;
    for (int i=0; i<n; i++){
        cin>>t;
        dp[t]=1;
    }
    for (int i=1; i<r+1; i++){
        if (dp[i]==0){
            cout<<i;
            return 0;
        }
    }
    cout<<"too late";
}