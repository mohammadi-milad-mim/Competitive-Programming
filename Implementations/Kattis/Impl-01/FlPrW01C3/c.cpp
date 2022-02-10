#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int m = n%3;
    int li[n];
    int t,s=0;
    for (int i=0; i<n; i++){
        cin>>t;
        s+=t;
        li[i]=t;
    }
    sort(li, li+n);
    int mi =0;
    for (int i=m; i<n; i+=3){
        mi+=li[i];
    }
    cout<<s-mi;
}