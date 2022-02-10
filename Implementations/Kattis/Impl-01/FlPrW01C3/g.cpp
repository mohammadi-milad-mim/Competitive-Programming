#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int m = n%3;
    int li[n];
    int t;
    for (int i=0; i<n; i++){
        cin>>t;
        li[i]=t;
    }
    sort(li, li+n);
    long long int mi =0;
    for (int i=m; i<n; i+=3){
        mi+=li[i];
    }
    cout<<mi;
}