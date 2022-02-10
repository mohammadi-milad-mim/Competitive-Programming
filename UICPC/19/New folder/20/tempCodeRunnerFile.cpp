#include <bits/stdc++.h>

using namespace std;

struct edge
{
    int u,v, num;
    long long int we;
    edge (int _u, int _v, int _w, int _n)
    {
        u = _u;
        v = _v;
        we = _w;
        num = _n;
    }
};


int main(){
    int n,m;
    cin>>n>>m;
    vector<edge> adj[10005];
    long long int dist [10005];
    long long int sofar [10005];
    fill_n(dist,n+5,LONG_MAX);
    fill_n(sofar,n+5,0);
    int a,b;
    long long ww;
    for (int i = 0; i < m; i++)
    {
        cin>>a>>b>>ww;
        if (a==b) continue;
        bool flag = false;
        for (int j = 0; j < adj[a].size(); j++)
        {
            if (adj[a][j].v==b){
                flag = true;
                if (adj[a][j].we > ww){
                    adj[a][j].we =ww;
                    adj[a][j].num = 1;
                }
                else if (adj[a][j].we == ww){
                    adj[a][j].num += 1;
                }
                break;            
            }
        }
        if (!flag){
            adj[a].push_back(edge(a,b,ww,1));
        }
        flag = false;
        for (int j = 0; j < adj[b].size(); j++)
        {
            if (adj[b][j].v==a){
                flag = true;
                if (adj[b][j].we > ww){
                    adj[b][j].we =ww;
                    adj[b][j].num = 1;
                }
                else if (adj[b][j].we == ww){
                    adj[b][j].num += 1;
                }
                break;            
            }
        }
        if (!flag){
            adj[b].push_back(edge(b,a,ww,1));
        }
    }
    
    dist[0]=0;
    priority_queue <pair <long long int,int>,vector<pair<long long int,int>>,greater<pair<long long int,int>> > pq;
    pq.push({dist[0],0});

    while (!pq.empty())
    {
        long long int u = pq.top().second, d = pq.top().first; pq.pop();
        
        if (d>dist[u]){
            continue;
        }

        for (int i = 0; i < adj[u].size(); i++)
        {
            int v=adj[u][i].v, nn=adj[u][i].num;
            long long w = adj[u][i].we;
            if ((w+dist[u])<dist[v])
            {
                
                dist[v] = w+dist[u];
                sofar[v]=(w*nn)+sofar[u];
                pq.push(make_pair(dist[v],v));
            }
            else if ((w+dist[u])==dist[v])
            {
                sofar[v]+=(w*nn)+sofar[u];
            }
        }
    }
    cout<<(sofar[n-1]*2);
}