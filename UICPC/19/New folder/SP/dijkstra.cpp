#include <bits/stdc++.h>

using namespace std;

struct edge
{
    int u,v, num;
    int weight;
    edge (int _u, int _v, int _w, int _n){
        u = _u;
        v = _v;
        weight = _w;
        num = _n;
    }
}
vector<edge> adj[10005];
vector <int> dist(10005, INT_MAX);

void dijkstra(int start)
{
    dist[start]=0;
    priority_queue <pair <int,int>,vector<pair<int,int>>,greater<pair<int,int>> > pq;
    pq.push(make_pair(dist[start],start));

    while (!pq.empty())
    {
        int u = pq.top().second, d = pq.top().first;
        pq.pop();
        if (d>dist[u]) continue;
        for (int i = 0; i < adj[u].size(); i++)
        {
            int v=adj[u][i].v, w = adj[u][i].weight;
            if (w+dist[u]<dist[v])
            {
                dist[v] = w+dist[u];
                pq.push(make_pair(dist[v],v));
            }
        }
    }
}