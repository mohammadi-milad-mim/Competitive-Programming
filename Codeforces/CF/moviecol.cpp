#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

struct cmp1 {
    bool operator() (const pair<int,int>& lhs, const pair<int,int>& rhs) const {
        return lhs.first < rhs.first;
    }
};

int main()
{
    int T; cin>>T;
    while (T--)
    {
        int m,q; cin>>m>>q;
        set<pii,cmp1> s;
        for(int i = 1; i <= m; i++) 
        {
            pii d = {i,i};
            s.insert(d);
        }
        for(int i = 0; i < m; i++) 
        {
            int q; cin >> q;
            pii d = *s.find({0,q});
            cout<<d.first<<endl;
            s.erase(d);
            d.first = -i;
            s.insert(d);
            cout<<d.first<<endl;
        }
    }
    
}