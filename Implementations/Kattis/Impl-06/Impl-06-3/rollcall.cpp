#include <bits/stdc++.h>
using namespace std;
bool sortbysec(const pair<pair<string,string>,int> &a,
              const pair<pair<string,string>,int> &b)
{
    if (a.first.second==b.first.second)
    {
        return (a.first.first < b.first.first);
    }
    return (a.first.second < b.first.second);
}
int main()
{
    string fn,ln,t;
    set<string> names;
    vector<pair<pair<string,string>,int>> alln;
    while(cin>>fn>>ln)
    {
        alln.push_back({{fn,ln},0});
        if (names.count(fn))
        {
            for (auto it = begin(alln); it != end(alln); ++it)
            {
               if (it->first.first == fn)
               {
                   it->second = 1;
               }
            }
        }
        names.insert(fn);
    }
    sort(alln.begin(), alln.end(), sortbysec);
    for (auto i: alln)
    {
        if (i.second == 1)
        {
            cout<<i.first.first<<' '<<i.first.second<<endl;
        }
        else
        {
            cout<<i.first.first<<endl;
        }
    }
}