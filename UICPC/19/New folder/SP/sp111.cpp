#include <bits/stdc++.h>

using namespace std;

struct edge
{
    int u,v;
    int weight;
    edge (int _u, int _v, int _w){
        u = _u;
        v = _v;
        weight = _w;
    }
};


void dijkstra(int start,vector<edge> adj[],int dist[])
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


int main()
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(true)
    {
        int n,m,qq,s;
        cin>>n>>m>>qq>>s;
        if (n+m+qq+s==0) return 0;
        int a,b,w;
        //adj.clear(); adj.resize(10005);
        
        vector<edge> adj[n+5];
        int dist[n+5];
        fill_n(dist,n+5,INT_MAX);
        for (int i = 0; i < m; i++)
        {
            cin>>a>>b>>w;
            adj[a].push_back(edge(a,b,w));
        }
        
        dijkstra(s,adj,dist);
        int no;
        for (int i = 0; i < qq; i++)
        {
            cin>>no;
            int d = dist[no];
            if (d!=INT_MAX) cout<<d<<'\n';
            else cout<<"Impossible"<<"\n";
        }
    cout<<"\n";
    }
}