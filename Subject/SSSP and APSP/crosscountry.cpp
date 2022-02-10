#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,s,t;
    cin>>n>>s>>t;
    vector<pair<int,int>> adjs[n];
    int tt;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>tt;
            if (j!=i)
            {
                adjs[i].push_back({tt,j});
            }
        }
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int dis[n];
    fill_n(dis, n, INT_MAX);
    pq.push({0, s});
    dis[s] = 0;
    while(!pq.empty()){
        auto p = pq.top();
        pq.pop();
        int d = p.first, u = p.second;
        if(dis[u] < d) // lazy delete
            continue;
        for(auto x : adjs[u])
            if(dis[x.second] > dis[u] + x.first) // relaxation
                dis[x.second] = dis[u] + x.first, pq.push({dis[x.second], x.second});
    }
    cout<<dis[t];
}