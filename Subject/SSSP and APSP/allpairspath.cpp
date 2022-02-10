#include <bits/stdc++.h>
using namespace std;

// APSP

// Floyd Warshall's Algorithm

// O(V ^ 3)

// Minimax path (max edge weight should be minimum): sp[i][j] = min(sp[i][j], max(sp[i][k], sp[k][j]))
// Shortest cycle: Initially set sp[i][i] = inf then the answer is min(sp[i][i]) for all i
// Diameter (max sp): max(sp[i][j]) for all i and j
// SCC: if sp[i][j] != inf and sp[j][i] != inf then i and j are in the same scc     

#define inf INT_MAX
#define num long long int

const int maxn = 153;

int n, e, q;
num sp[maxn][maxn];


int main()
{
    while(true)
    {
        cin >> n >> e>>q;
        if (n+e+q==0) break;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++){
                if(i == j)
                    sp[i][j] = 0;
                else
                    sp[i][j] = inf;
            }
        for(int i = 0; i < e; i++){
            int u, v, w;
            cin >> u >> v >> w; // edges are directed
            sp[u][v] = min(sp[u][v], (num)w);
        }
        for(int k = 0; k < n; k++)
            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++)
                    if(sp[i][k] != inf && sp[k][j] != inf)
                        sp[i][j] = min(sp[i][j], sp[i][k] + sp[k][j]);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                for(int k = 0; k < n; k++)
                    if(sp[i][k] != inf && sp[k][j] != inf && sp[k][k] < 0)
                        sp[i][j] = -inf;
        int src, dst;
        for (int i = 0; i < q; i++)
        {
        cin >> src >> dst;
        if (sp[src][dst]==inf) cout << "Impossible" <<'\n';
        else if (sp[src][dst]==-inf) cout << "-Infinity" <<'\n';
        else cout << sp[src][dst] <<'\n';
        }
        cout<<"\n";
    }
}