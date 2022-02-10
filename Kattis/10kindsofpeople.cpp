#include <bits/stdc++.h>
using namespace std;

#define inf INT_MAX
typedef pair<int,int> pii;

int n, src;
int r,c;
int adj[1003][1003];
int vis[1003][1003];
int area[1003][1003];
queue<pii> bfs;
pii dirs[4] = {{-1,0},{1,0},{0,1},{0,-1}};

bool inrange(int i, int j)
{
    return (i>=0 and j>=0 and i<r and j<c);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>r>>c;
    for (int i = 0; i < r; i++)
    {
        string line; cin>>line;
        for (int j = 0; j < c; j++)
        {
            int temp = int(line[j])-int('0')+1;
            adj[i][j]=temp;
        }
    }
    int area_num = 1;
    int q; cin>>q;
    while (q--)
    {
        int is,js, id,jd;
        cin>>is>>js>>id>>jd;
        is--; js--; id--; jd--;
        if (!vis[is][js])
        {
                 bfs.push({is,js});
                 vis[is][js]=1;
                 while(!bfs.empty())
                 {
                     pii t = bfs.front(); bfs.pop();
                     area[t.first][t.second]=area_num;
                     for (int tt=0; tt<4; tt++)
                     {
                         pii v = dirs[tt];
                         int ii = t.first+v.first;
                         int jj = t.second+v.second;
                         if (inrange(ii,jj) and (!vis[ii][jj]) and (adj[ii][jj]==adj[is][js]))
                         {
                             bfs.push({ii,jj});
                             vis[t.first][t.second]=1;
                         }
                     }
                 }
            area_num++;
        }
        if (area[is][js]==area[id][jd])
        {
            if (adj[is][js]==1)
            {
                cout<<"binary"<<"\n";
             }
            else
            {
                cout<<"decimal"<<"\n";
            }
        }
            else
        {
            cout<<"neither"<<"\n";
        }
    }
}