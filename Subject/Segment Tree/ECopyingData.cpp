#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100007;
int n, t[4*MAXN];

void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = t[v*2] + t[v*2+1];
    }
}

int sum(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return sum(v*2, tl, tm, l, min(r, tm))
           + sum(v*2+1, tm+1, tr, max(l, tm+1), r);
}

void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = t[v*2] + t[v*2+1];
    }
}

int query(int v, int tl, int tr, int l, int r)
{
    if(l > r)
        return 0; // Nill
    if(l == tl && r == tr)
        return t[v]; // Hit
    int tm = (tl + tr) / 2;
    int mask1 = query(2 * v, tl, tm, l, min(tm, r));
    int mask2 =  query(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
    return mask1 + mask2; // Combine
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m; cin>>n>>m;
    int a[n],b[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin>>b[i];
    }

	build(b, 1, 0, n-1);
    int op;
    for (int i = 0; i < m; i++)
    {
        cin>>op;
        if (op==2)
        {
            int x; cin>>x; x--;
            cout<<query(1,0,n-1, x, x)<<'\n';
        }
        else if (op==1)
        {
            int x,y,k; cin>>x>>y>>k; x--;y--;
            for (int j = 0; j < k; j++)
            {
                update(1,0,n-1,y+j,a[x+j]);
            }
        }
    }
}