#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    string f,s,c;
    set <pair<string, string>> sets;
    vector<string> ve;
    unordered_map <string, int> um;
    for (int i = 0; i < n; i++)
    {
        cin>>f>>s>>c;
        string res = f + '+' + s;
        sets.insert(make_pair(res,c));
    }
    for(auto a:sets){
        um[a.second]++;
    }
    for(auto a:um){
        ve.push_back(a.first);
    }
    sort(ve.begin(),ve.end());
    for (int i = 0; i < ve.size(); i++)
    {
        cout<<ve[i]<<' '<<um[ve[i]]<<endl;
    }
    
}   