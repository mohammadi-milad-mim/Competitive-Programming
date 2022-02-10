#include <bits/stdc++.h>

using namespace std;

int main(){
    long long int n,t, ma=-1,c;
    long long int lis[n];
    vector <long long int> res;
    cin>>n;
    for (long long int i=0; i<n; i++){
        cin>>t;
        lis[i]=t;
        if (t>ma){
            c+=1;
            res.push_back(t);
            ma = t;
            if (ma == n) break;
        }
        cout<<c<<'\n';
        for (auto i: res) cout << i << ' ';
}
}