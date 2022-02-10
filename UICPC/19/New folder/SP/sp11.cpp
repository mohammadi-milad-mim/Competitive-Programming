#include <bits/stdc++.h>

using namespace std;


int main()
{
    while(true)
    {
        int n,m,qq,s;
        cin>>n>>m>>qq>>s;
        if (n+m+qq+s==0) return 0;
        int a,b,ww;
        vector<vector<pair<int, int>>> adj(10005);
        int dist[10005];
        priority_queue<pair<int, int>> q;
        for (int i = 0; i < m; i++)
        {
            cin>>a>>b>>ww;
            adj[a].push_back({b,ww});
        }
        fill_n(dist,n+5,20000000);
        q.push({0,s});
        dist[s]=0;
            pair<int, int> p;
            int w, u;
            while(!q.empty())
            {
                p = q.top(); q.pop();
                w = p.first; u = p.second;
                if(w>dist[u]) continue;

                for(auto v : adj[u])
                {
                    if(dist[v.first] > dist[u] + v.second)
                    {
                        dist[v.first] = dist[u] + v.second;
                        q.push({dist[v.first], v.first});
                    }
                }
            }
        int no;
        for (int i = 0; i < qq; i++)
        {
            cin>>no;
            int d = dist[no];
            if (d!=20000000) cout<<d<<'\n';
            else cout<<"Impossible"<<"\n";
        }
    cout<<"\n";
    }
}
