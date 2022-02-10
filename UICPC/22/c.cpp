#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
// std::cout << std::setprecision(3) << std::fixed << doubllle;
// sort(arr, arr + n, greater<int>());
//c = ::tolower(c);
//for (int i = 0; i < s.size(); i++) {
//s[i] = tolower(s[i]);
//multiset<lli, greater<lli>> mset;
//int dx[4]={0,-1,0,1};
//int dy[4]={-1,0,1,0};

int n, m;
const int num = 30000+5;
int c[100+5], s[num], state[num];
pair<int, int> each[num];//which item//from where
vector<int> ans;
//map<int,int> Map;

void recursive(int x){
    if(each[x].first==-1) return;
    ans.push_back(each[x].first);
    // cout<<each[1].first<<" "<<each[1].second;
    recursive(each[x].second);
}
int main(){
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>c[i]; 
    }
    //sort(c, c+n);

    state[0]=1;
    each[0]={-1,-1};

    for(int i=1; i<=n; i++){
        for(int k=0; k<=num; k++){
            if(k+c[i] > num) break;

            if(state[k] == 1){
                if(state[k+c[i]] == 0){
                    state[k+c[i]] = 1;
                    each[k+c[i]] = {i,k};
                }
                else if(state[k+c[i]] == 1){
                    state[k+c[i]] = -1;
                }
            }
            else if(state[k] == -1 ){
                state[k+c[i]] = -1;
            }
        }
    }

    cin>>m;
    for(int i=1; i<=m; i++){
        cin>>s[i];
        if(state[s[i]]==0){
            cout<<"Impossible"<<'\n';
            continue;
        }
        else if(state[s[i]]==-1){
            cout<<"Ambiguous"<<'\n';
            continue;
        }
        ans.clear();
        recursive(s[i]);
        sort(ans.begin(), ans.end());
        for(auto x : ans){
            cout<<x<<" ";
        }
        // for(int x=ans.size()-1; x>=0; x--){
        //     cout<<ans[x]<<" ";
        // }
        cout<<'\n';
    }
}