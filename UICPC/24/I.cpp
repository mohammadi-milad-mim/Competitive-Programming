#include <bits/stdc++.h>
using namespace std;
typedef unsigned  long ul;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k; cin>>n>>k;
    pair <ul,int> H[n];
    pair <ul,int> A[n];
    pair <ul,int> D[n];
    ul a,h,d;
    for (int i = 0; i < n; i++)
    {
        cin>>a>>d>>h;
        H[i].first=h; H[i].second=i;
        D[i].first=d; D[i].second=i;
        A[i].first=a; A[i].second=i;
    }
    sort(H, H+n);
    sort(A, A+n);
    sort(D, D+n);
    set<int, greater<int> > S;
    int co=n-1;
    while(co>=n-k)
    {
        S.insert(A[co].second);
        S.insert(H[co].second);
        S.insert(D[co].second);
         co-=1;
    }
    int res = S.size();
    cout<<res;
}