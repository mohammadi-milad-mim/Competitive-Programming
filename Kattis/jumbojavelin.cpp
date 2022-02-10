#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,t;
    cin>>n;
    int s = (0 -n + 1);
    for (int i=0; i<n; i++){
        cin>>t;
        s+=t;
    }
    cout<<s;
}
