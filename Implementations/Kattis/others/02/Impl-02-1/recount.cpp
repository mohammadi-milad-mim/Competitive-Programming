#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<string, int> list;
    vector<string> res;
    string str;
    int ma=0;
    int t;
    while (true)
    {
        getline(cin, str);
        if (str=="***") break;
        auto itr = list.find(str);
        if (itr != list.end())
        {
            itr->second++;
            t = itr->second;
            if (t==ma)
            {
                res.push_back(str);
            }
            else if (t>ma)
            {
                 res.clear();
                 res.push_back(str);
                 ma=t;
            }
        }
        else
        {
            list.insert({ str, 1 });
        }
    }
    if (res.size()>1)
    {
        cout<<"Runoff!";
    }
    else if (res.size()==0)
    {
        cout<<"Runoff!";
    }
    else
    {
        cout<<res.at(0);
    }
}