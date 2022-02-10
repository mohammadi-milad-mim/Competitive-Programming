#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,t;
    int s=0;
    cin>>n;
    for (int i=0; i<n; i++){
        cin>>t;
        if (t<0) s+=1;
    }
    cout<<s;
}
