#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 3;
int m, r;
int t[4 * maxn];
int a[maxn];
int mp[maxn];

void build(int v, int tl, int tr){
    if(tl == tr)
        t[v] = a[tl];
    else{
        int tm = (tl + tr) / 2;
        build(2 * v, tl, tm);
        build(2 * v + 1, tm + 1, tr);
        t[v] = t[2 * v] + t[2 * v + 1];
    }
}

void update(int v, int tl, int tr, int pos, int val){
    if(tl == tr)
        t[v] = val;
    else{
        int tm = (tl + tr) / 2;
        if(pos <= tm)
            update(2 * v, tl, tm, pos, val);
        else
            update(2 * v + 1, tm + 1, tr, pos, val);
        t[v] = t[2 * v] + t[2 * v + 1];
    }
}

int query(int v, int tl, int tr, int l, int r){
    if(l > r)
        return 0;
    if(l == tl && r == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    int p1 = query(2 * v, tl, tm, l, min(tm, r));
    int p2 = query(2 * v + 1, tm + 1, tr, max(tm + 1, l), r);
    return p1 + p2;
}

int main()
{
    int T; cin>>T;
    while (T--)
    {
        cin>>m>>r;
        for (int i = 0; i <= r; i++)
            a[i]=0;
        for (int i = 0; i <= m; i++)
        {
            a[i+r]=1;
            mp[i]=i+r;
        }
        build(1, 0, r+m - 1);
        int q;
        for (int i = 0; i < r; i++)
        {
            cin>>q; q--;
            cout<<query(1,0,r+m-1,0,mp[q]-1)<<" ";
            update(1,0,r+m-1,mp[q],0);
            mp[q]=r-i-1;
            update(1,0,r+m-1,r-i-1,1);
        }
    cout<<'\n';
    }
    
}
