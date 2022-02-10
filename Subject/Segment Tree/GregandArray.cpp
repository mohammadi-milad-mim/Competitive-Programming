#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100007;
int n, t[4*MAXN],t2[4*MAXN];

void build(int a[], int v, int tl, int tr) 
{
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = t[v*2] + t[v*2+1];
    }
}

int sum(int v, int tl, int tr, int l, int r) 
{
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return sum(v*2, tl, tm, l, min(r, tm)) + sum(v*2+1, tm+1, tr, max(l, tm+1), r);
}

int sum2(int v, int tl, int tr, int l, int r) 
{
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return t2[v];
    }
    int tm = (tl + tr) / 2;
    return sum(v*2, tl, tm, l, min(r, tm)) + sum(v*2+1, tm+1, tr, max(l, tm+1), r);
}

void update(int v, int tl, int tr, int pos, int new_val) 
{
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
void update2(int v, int tl, int tr, int pos, int new_val) 
{
    if (tl == tr) {
        t2[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t2[v] = t2[v*2] + t2[v*2+1];
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

int query2(int v, int tl, int tr, int l, int r)
{
    if(l > r)
        return 0; // Nill
    if(l == tl && r == tr)
        return t2[v]; // Hit
    int tm = (tl + tr) / 2;
    int mask1 = query(2 * v, tl, tm, l, min(tm, r));
    int mask2 =  query(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
    return mask1 + mask2; // Combine
}

int main()
{
    int n,m,k; cin>>n>>m>>k;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int opr[m][3];
    for (int i = 0; i < m; i++)
    {
        cin>>opr[i][0]>>opr[i][1]>>opr[i][2];
    }
    int quer[k][2];
    for (int i = 0; i < k; i++)
    {
        cin>>quer[i][0]>>quer[i][1];
    }
    for (int i = 0; i < k; i++)
    {
        update2(1,0,n-1,)
    }
}