#include<bits/stdc++.h>

using namespace std;

int main(){
    long long int n;
    cin>>n;
    long long int sq = pow(2,n);
    //cout<<sq<<'\n';
    long long int s = 1;
    s+=(3+(sq*2+1))*sq/2;
    cout<<s;
}
