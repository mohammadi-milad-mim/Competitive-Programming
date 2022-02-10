#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;

int main()
{
    int n; cin>>n;
    vector<pii> se;
    se.push_back({1,0});
    int s,b;
    int closest = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        cin>>s>>b;
        vector<pii> temp;
        int sour,bitt,res;
        for (auto v:se)
        {
            sour = v.first * s;
            bitt = v.second + b;
            res = abs(sour-bitt);
            if (res<closest)
            {
                closest = res;
            }
            temp.push_back({sour,bitt});
        }
        se.push_back({s,b});
        res = abs(s-b);
        if (res<closest)
        {
            closest = res;
        }
        for (auto v:temp)
        {
            se.push_back(v);
        }
    }
    cout<<closest;
}