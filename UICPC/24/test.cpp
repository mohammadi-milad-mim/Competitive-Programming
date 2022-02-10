#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
// cout << setprecision(3) << fixed << doubllle;
// sort(arr, arr + n, greater<int>());
//c = ::tolower(c);
//for (int i = 0; i < s.size(); i++) {
//s[i] = tolower(s[i]);
//multiset<lli, greater<lli>> mset;
//int dx[4]={0,-1,0,1};
//int dy[4]={-1,0,1,0};
//M_PI >>Pi

int n;
const int num = 100+5;
int h[num][num];
bool  visited[num][num];
int dx[4]={0,-1,0,1};
int dy[4]={-1,0,1,0};
bool inrange(int x, int y){
    return (x>=0 && x<n && y>=0 && y<n);
}
set<pair<int, pair<int,int>>> pq;
pair<int,int> track[num][num];
bool bfs(){
    int x = pq.begin()->second.first;
    int y = pq.begin()->second.second;
    pq.erase(pq.begin());
    visited[x][y]=1;
    if(x==n-1 && y==n-1){
        return 0;
    }
    for(int i=0; i<4; i++){
        int x2 = x+dx[i];
        int y2 = y+dy[i];
        if(inrange(x2,y2)){
              if(!visited[x2][y2]){
                  pq.insert({h[x2][y2], {x2,y2}});
                  track[x2][y2] = {x, y};
              }  
        }
    }
    return 1;
}
int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>h[i][j];
        }
    }
    pq.insert({h[0][0], {0, 0}});
    while(!pq.empty()){
        if(!bfs()) break;
    }
    int i=n-1, j=n-1;
    int mx = -1;
    while(1){
        mx = max(mx, h[i][j]);
        if(!i && !j) break;
        i = track[i][j].first;
        j = track[i][j].second;
    }
    cout<<mx;
}