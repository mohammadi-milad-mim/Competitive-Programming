#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int>> pipii;
typedef vector<pair<int,pair<int,int>>> vpipii;


int main()
{
    int n; cin>>n;
    vpipii plats;
    int y, x1,x2;
    for (int i = 0; i < n; i++)
    {
        cin>>y>>x1>>x2;
        plats.push_back({y,{x1,x2-1}});
    }
    plats.push_back({0,{0,10007}});
    int greed[10007];
    fill_n(greed,10007,0);
    sort(plats.begin(), plats.end());
    int total = 0;
    for (auto it = begin (plats)+1; it != end (plats); ++it)
    {
        int yn = it->first;
        int x1n = it->second.first;
        int x2n = it->second.second;
        total+=yn-greed[x1n];
        total+=yn-greed[x2n];
        for (int j = x1n; j <= x2n; j++)
        {
            greed[j]=yn;
        }
    }
    cout<<total;
}