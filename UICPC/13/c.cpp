#include <bits/stdc++.h>

using namespace std;

bool inrange(int i, int j,int m, int n){
    if ((i>=0) && (i<m) && (j>=0) && (j<n)){
        return true;
    }
    else{
        return false;
    }
}


int main(){
    int m,n;
    cin>>m>>n;
    int mp[m][n];
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            cin>>mp[i][j];
        }
    }
    int x,y;
    cin >>x>>y;
    x--;
    y--;
    vector <int> cars;
    vector <int> visited;
    bool flag = true;

    while (flag){
        bool pflag = true;

        if (inrange(x,y+1,m,n)){
            if (mp[x][y+1] == mp[x][y]){
                pflag = false;
                cars.push_back(mp[x][y]);
                if (inrange(x,y+2,m,n)){
                    if (mp[x][y+2]==-1){
                        for(int p = cars.size() -1 ; p >= 0 ; p--){
                            cout<<cars[p]<<' ';
                        }
                        return 0;
                    }
                    else if (mp[x][y+2]==-2){
                        cout<<"impossible";
                        return 0;
                    }
                    else {
                        if (find(visited.begin(), visited.end(), mp[x][y+2]) != visited.end()){
                            cout<<"impossible";
                            return 0;
                            }
                        else {
                            visited.push_back(mp[x][y]);
                            y+=2;
                            }
                        }
                    
                    }
                else {
                        cout<<"impossible";
                        return 0;
                    }
                }

            }

        if ((inrange(x,y-1,m,n)) && pflag){
            if (mp[x][y-1] == mp[x][y]){
                pflag = false;
                cars.push_back(mp[x][y]);
                if (inrange(x,y,m,n)){
                    if (mp[x][y-2]==-1){
                        for(int p = cars.size() -1 ; p >= 0 ; p--){
                            cout<<cars[p]<<' ';
                        }
                        return 0;
                    }
                    else if (mp[x][y-2]==-2){
                        cout<<"impossible";
                        return 0;
                    }
                    else {
                        if (find(visited.begin(), visited.end(), mp[x][y-2]) != visited.end()){
                            cout<<"impossible";
                            return 0;
                            }
                        else {
                            visited.push_back(mp[x][y-2]);
                            y-=2;
                            }
                        }
                    
                    }
                else {
                        cout<<"impossible";
                        return 0;
                    }
                }

            }

        if ((inrange(x+1,y,m,n)) && pflag){
            if (mp[x+1][y] == mp[x][y]){
                pflag = false;
                cars.push_back(mp[x][y]);
                if (inrange(x+2,y,m,n)){
                    if (mp[x+2][y]==-1){
                        for(int p = cars.size() -1 ; p >= 0 ; p--){
                            cout<<cars[p]<<' ';
                        }
                        return 0;
                    }
                    else if (mp[x+2][y]==-2){
                        cout<<"impossible";
                        return 0;
                    }
                    else {
                        if (find(visited.begin(), visited.end(), mp[x+2][y]) != visited.end()){
                            cout<<"impossible";
                            return 0;
                            }
                        else {
                            visited.push_back(mp[x+2][y]);
                            x+=2;
                            }
                        }
                    
                    }
                else {
                        cout<<"impossible";
                        return 0;
                    }
                }

        }

        if ((inrange(x-1,y,m,n)) && pflag){
            if (mp[x-1][y] == mp[x][y]){
                pflag = false;
                cars.push_back(mp[x][y]);
                if (inrange(x-2,y,m,n)){
                    if (mp[x-2][y]==-1){
                        for(int p = cars.size() -1 ; p >= 0 ; p--){
                            cout<<cars[p]<<' ';
                        }
                        return 0;
                    }
                    else if (mp[x-2][y]==-2){
                        cout<<"impossible";
                        return 0;
                    }
                    else {
                        if (find(visited.begin(), visited.end(), mp[x-2][y]) != visited.end()){
                            cout<<"impossible";
                            return 0;
                            }
                        else {
                            visited.push_back(mp[x][y]);
                            x-=2;
                            }
                        }
                    
                    }
                else {
                        cout<<"impossible";
                        return 0;
                    }
                }

            }
        if(pflag) {
            cout<<"impossible";
            return 0;
        }
        }
    }