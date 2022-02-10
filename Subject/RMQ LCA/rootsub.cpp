
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long

int n;
vector<int> g[200010];
int tin[200010], tout[200010], timer = 0;
int alog[200010][20];

void dfs(int u, int p) 
{
    tin[u] = timer++;

    alog[u][0] = p;
    for (int i = 1; i < 20; i++) 
    {
        alog[u][i] = alog[alog[u][i - 1]][i - 1];
    }

    for (auto v : g[u]) 
    {
        if (v != p) dfs(v, u);
    }
    tout[u] = timer++;
}

bool ancestor(int cur, int anc) 
{
    return tin[anc] <= tin[cur] && tout[cur] <= tout[anc];
}

int LCA(int x, int y) 
{
    if (ancestor(x, y)) {return y;}
    if (ancestor(y, x)) {return x;}

    for (int i = 19; i >= 0; i--) 
    {
        if (!ancestor(y, alog[x][i])) {x = alog[x][i];}
    }
    return alog[x][0];
}

int Pow(int a, int m) 
{
    if (m == 0) {return 1;}
    int re = Pow(a, m / 2);
    if (m % 2 == 0) {return re * re;}
    return re * re * a;
}

int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int q;
    cin >> n >> q;
    for (int i=0; i<n-1; i++) 
    {
        int u, v;
        cin >> u >> v, u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(0, 0);

    while (q--) 
    {
        int u, v;
        cin >> u >> v, u--, v--;
        if (u == v) 
        {
            cout << n << '\n';
            continue;
        }
        int p = LCA(u, v);
        ll l = 0;
        for (int i = 19; i >= 0; i--) 
        {
            if (ancestor(alog[u][i], p) && !ancestor(p, alog[u][i])) 
            {
                l += Pow(2, i);
                u = alog[u][i];
            }
        }
        if (u != p) l++;
        for (int i = 19; i >= 0; i--) 
        {
            if (ancestor(alog[v][i], p) && !ancestor(p, alog[v][i])) 
            {
                l += Pow(2, i);
                v = alog[v][i];
            }
        }
        if (v != p) {l++;}
        cout << n + (l * (l + 1) / 2) << '\n';
    }
}