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
    plats.push_back({0,{0,10001}});
    sort(plats.begin(), plats.end());
    int total = 0;
    for (auto it = begin (plats)+1; it != end (plats); ++it) 
    {
        int yn = it->first;
        int x1n = it->second.first;
        int x2n = it->second.second;
        bool x1f = false;
        bool x2f = false;
        auto it2 = it-1;
        while (it2 >= begin(plats) && !(x1f && x2f))
        {
            int yb = it2->first;
            int x1b = it2->second.first;
            int x2b = it2->second.second;
            if (!x1f && x1n<=x2b && x1n>=x1b)
            {
                total+=yn-yb;
                x1f = true;
            }
            if (!x2f && x2n<=x2b && x2n>=x1b)
            {
                total+=yn-yb;
                x2f = true;
            }
            it2--;
        }
    }
    cout<<total;
}