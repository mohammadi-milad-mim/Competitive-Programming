#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    int ma;
    cin>>n>>ma;
    int li[n];
    for (int i=0; i<n; i++){
        cin>>li[i];
    }
    sort(li, li + n);
    int res = 0;
    int flag=1;
    for (int i=0;i<n-1; i++){
        int su = li[i]+li[i+1];
        //cout<<su<<'\n';
        if (su>ma){
            res = i;
            flag=0;
            break;
        }
    }
    if (flag) cout<<n;
    else cout<<res+1;
}