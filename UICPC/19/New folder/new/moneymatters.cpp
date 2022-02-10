#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int mo[n];
    for (int i = 0; i < n; i++)
    {
        cin>>mo[i];
    }
    set <int> adj[n];
    int a,b;
    for (int i = 0; i < m; i++)
    {
        cin>>a>>b;
        adj[a].insert(b);
        adj[b].insert(a);
    }
    int vis[n] = {0};
    bool flag=true;
    for (int i = 0; i < n; i++)
    {
        if (vis[i]) continue;
        else
        {
            int su=0;
            stack<int> st;
            st.push(i);
            int t;
            while(!st.empty())
            {
                t = st.top();
                st.pop();
                if (vis[t]) break;
                su+=mo[t];
                vis[t]=1;
                set<int>::iterator it = adj[t].begin();
                while (it != adj[t].end())
                    {
                        int tt = *it;
                        if (!vis[tt]){
                            st.push(*it);
                        }
                        it++;
                    }
            }
            if (su)
            {
                flag=false;
                break;
            }

        }

    }
    if (flag) cout<<"POSSIBLE";
    else cout<<"IMPOSSIBLE";
}