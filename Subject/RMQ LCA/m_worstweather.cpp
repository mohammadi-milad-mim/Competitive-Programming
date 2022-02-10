#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e4 + 7;

int n, years[maxn], rains[maxn], seg[4 * maxn], ind[4 * maxn];

void build(int v, int tl, int tr)
{
    if(tl == tr)
        {seg[v] = rains[tl], ind[v] = tl;}
    else
    {
        int mid = (tl + tr) / 2;
        build(2 * v, tl, mid);
        build(2 * v + 1, mid+1, tr);
        seg[v] = seg[2 * v], ind[v] = ind[2 * v];
        if(seg[2 * v + 1] > seg[v])
            seg[v] = seg[2 * v + 1], ind[v] = ind[2 * v + 1];
    }
}

pair<int, int> query(int v, int tl, int tr, int l, int r)
{
    pair<int, int> ans = {0, -1};
    if(l > r)
        {return ans;}
    if(tl == l && tr == r)
        {return {seg[v], ind[v]};}
    int mid = (tl + tr) / 2;
    pair<int, int> left = query(2 * v, tl, mid, l, min(r, mid));
    if(left.first > ans.first)
        {ans = left;}
    pair<int, int> right = query(2 * v + 1, mid+1, tr, max(l, mid+1), r);
    if(right.first > ans.first)
        {ans = right;}
    return ans;
}
//segment tree impilimantaton form "mohsendb7008"
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(true)
    {
        cin>>n;
        int year,rain;
        for(int i = 0; i < n; i++)
        {
            cin>>year>>rain;
            years[i]=year;
            rains[i]=rain;
        }
        if(n){build(1, 0, n-1);}
            
        int m, X, Y,y,x;
        cin>>m;
        if(!m){break;}
        while(m--)
        {
            cin>>y>>x;
            Y = lower_bound(years, years+n, y) - years;
            X = lower_bound(years, years+n, x) - years;
            if(Y < n && X < n && years[Y] == y && years[X] == x)
            //We know both Y and X years
            {
                if(rains[X] > rains[Y])
                {
                    // the second rule
                    cout<<"false"<<'\n';
                    continue;
                }
                if(query(1, 0, n-1, Y+1, X).second != X)
                //if the max in range(Y,X) not exactly point to X
                {
                    cout<<"false"<<'\n';
                    continue;
                }
                if(x - y == X - Y)
                // we know all the rains in these years
                {
                    cout<<"true"<<'\n';
                    continue;
                }
            }
            else if(Y < n && years[Y] == y)
            //we know year Y
            {
                if(query(1, 0, n-1, Y, X-1).first != rains[Y])
                // if any year have most rain than year Y in range(Y,X-1)
                {
                    cout<<"false"<<'\n';
                    continue;
                }
            }
            else if(X < n && years[X] == x)
            //we know year X
            {
                if(query(1, 0, n-1, Y, X).second != X)
                //if the max in range(Y,X) not exactly point to X
                {
                    cout<<"false"<<'\n';
                    continue;
                }
            }
            cout<<"maybe"<<'\n';
            //in any other situation
        }
        cout<<'\n';
    }
}