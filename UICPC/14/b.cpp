#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

int n, m;
int grid[1005][1005];
queue<pair<int, int>> q;
bool vis[1005][1005];
pair<int, int> adj[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool inrange(int i, int j){
    return i>=0 && i<n+1 && j>= 0 && j<m+1;
}

int main()
{
    int cnt = 0;
    cin>>n>>m;
    
    for (int i = 0; i < n+2; i++) {grid[i][0] = 0; grid[i][n+1] = 0;}
    for (int i = 0; i < m+2; i++) {grid[0][i] = 0; grid[m+1][i] = 0;}

    for (int i = 1; i < n+1; i++){
        string s;
        cin>>s;
        for (int j = 1; j < m+1; j++){
            grid[i][j]=int(s[j-1])-48;
        }
    }
    memset(vis, false, sizeof(vis));

    q.push({0, 0});
    vis[0][0] = true;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        cout<<
        for (int k = 0; k < 4; k++)
        {
            int i = adj[k].first;
            int j = adj[k].second;
            if (inrange(x+i, y+j)){
                if (grid[x+i][y+j] == 0){ //valid
                    q.push({x+i, y+j});
                    vis[x+i][y+j] = true;
                }
                else if (grid[x+i][y+j] == 1){
                    cnt++;
                }
            }
        }
    }
    cout<<cnt<<endl;
}