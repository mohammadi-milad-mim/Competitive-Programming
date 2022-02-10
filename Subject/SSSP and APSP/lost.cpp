#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    vector<pair<int,int>> adjs[n];
    cin>>n>>m;
    map<string,int> mp;
    string t;
    for (int i = 0; i < n; i++)
    {
        cin>>t;
        mp.insert({t,i});
    }
    string a,b;
    int aa,bb,w;
    for (int i = 0; i < m; i++)
    {
        cin>>a>>b>>w;
        auto it = mp.find(a);
        aa= it->second;
        auto it = mp.find(b);
        bb= it->second;
        adjs[aa].push_back({w,bb});
        adjs[bb].push_back({w,aa});
    }
    
    
}