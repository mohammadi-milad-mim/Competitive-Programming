#include <bits/stdc++.h>
using namespace std;

// SSSP, Dijkstra

// Dijkstra's Algorithm

// O(V + E * logV)

#define inf INT_MAX

vector<pair<int,int>> adjs[1003]; // {weight, dst}
pair<int,int> tim[1003][1003];
int adjs2[1003][1003];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int dis[1003];

int main(){
    // read the graph
    int n,m;
    cin>>n>>m;
    int s,e,t,g;
    cin>>s>>e>>t>>g;
    s--; e--;
    int geo[g];
    for (int i = 0; i < g; i++)
    {
        cin>>geo[i];
        geo[i]--;
    }
    int a,b,w;
    for (int i = 0; i < m; i++)
    {
        cin>>a>>b>>w;
        a--; b--;
        adjs[a].push_back({w,b});
        adjs[b].push_back({w,a});
        adjs2[a][b]=w;
        adjs2[b][a]=w;
        tim[a][b]={-1,-1};
        tim[b][a]={-1,-1};
    }
    int aa,bb;
    int mi = 0;
    for (int i = 0; i < g-1; i++)
    {
        aa=geo[i];
        bb=geo[i+1];
        tim[aa][bb]={mi,mi+adjs2[aa][bb]-1};
        tim[bb][aa]={mi,mi+adjs2[aa][bb]-1};
        mi=mi+adjs2[aa][bb];
    }
    mi = t;
    fill_n(dis, n, inf);
    pq.push({t, s});
    dis[s] = t;
    while(!pq.empty()){
        auto p = pq.top();
        pq.pop();
        int d = p.first, u = p.second;
        if(dis[u] < d) // lazy delete
            continue;
        for(auto x : adjs[u])
        {
            int wait = 0;
            if(tim[u][x.second].first !=-1)
            {
                if (dis[u]>=tim[u][x.second].first && dis[u]<=tim[u][x.second].second)
                {
                    wait=tim[u][x.second].second-dis[u];
                }
            }
            if(dis[x.second] > dis[u] + x.first+wait) // relaxation
                dis[x.second] = dis[u] + x.first + wait, pq.push({dis[x.second], x.second});
        }
    }
    cout<<dis[e]-t+1;
}