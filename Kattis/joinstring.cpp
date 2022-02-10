#include <bits/stdc++.h>
using namespace std;
int n;
//vector<int> nums[100007];
vector<string> st[100007];
//string arr[100007];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    string t;
    for (int i = 0; i < n; i++)
    {
        //nums[i].push_back(i);
        cin>>t;
        st[i].push_back(t);
    }
    int a=0;
    int b;
    for (int i = 0; i < n-1; i++)
    {
        cin>>a>>b;
        a--;b--;
        st[a].insert(st[a].end(), st[b].begin(), st[b].end());
        st[b].clear();
    }
    for (auto v: st[a])
    {
        cout<<v;
    }
}