#include<bits/stdc++.h>
using namespace std;

const int maxn = 10005;
const int Maxn = 250005;

int dist[maxn],sofar[maxn];


struct edge
{
    int v;
    //long long num;
    int we;
    edge (int _v, long long int _w)
    {
        //u = _u;
        v = _v;
        we = _w;
        //num = _n;
    }
};

vector<node> adj[maxn];
int a[Maxn],b[Maxn],c[Maxn];
priority_queue<pair<int,int> >Q;


int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&a[i],&b[i],&c[i]);
        adj[a[i]].push_back(edge{b[i],c[i]});
        adj[b[i]].push_back(edge(a[i],c[i]));
    }
    fill_n(dist,n+5,LONG_MAX);
    fill_n(sofar,n+5,LONG_MAX);

    Q.push({0,0});
    dist[0]=0;
    while(!Q.empty()){
        int now=Q.top().second; Q.pop();
        
        for(int i=0;i<E[now].size();i++){
            int v=E[now][i].x;
            int sp=E[now][i].y;
            if(d1[v]>d1[now]+sp){
                d1[v]=d1[now]+sp;
                Q.push(make_pair(-d1[v],v));
            }
        }
    }

    Q.push(make_pair(0,n-1));
    d2[n-1]=0;
    while(!Q.empty()){
        int now=Q.top().second;
        Q.pop();
        for(int i=0;i<E[now].size();i++){
            int v=E[now][i].x;
            int sp=E[now][i].y;
            if(d2[v]>d2[now]+sp){
                d2[v]=d2[now]+sp;
                Q.push(make_pair(-d2[v],v));
            }
        }
    }
    long long ans = 0;
    for(int i=1;i<=m;i++){
        if(d1[n-1]==d1[a[i]]+d2[b[i]]+c[i])
            ans+=2ll*c[i];
        else if(d1[n-1]==d2[a[i]]+d1[b[i]]+c[i])
            ans+=2ll*c[i];
    }
    cout<<ans<<endl;
    }
}