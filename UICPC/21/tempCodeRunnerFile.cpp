#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
vector<pair<pair<int, int>, int>> drn; //loc, v, ind
set<pair<double, pair<int, int>>> col; //xt, ind
bool cmp(pair<pair<int, int>, int> x, pair<pair<int, int>, int> y)
{
    return x.first.first < y.first.first;
}

double colid(int x, int xt, int y, int yt)
{
    if (yt == xt) return 0;
    return double(y-x)/double(xt - yt);
}

bool inrange(int ind1, int ind2)
{
    return ind1 >= 0 && ind2>=0 && ind1 < n && ind2 < n;
}

int main()
{
    
    cin>>n;
    bool aliv[n+5];
    int x, y;
    for (int i = 0; i < n; i++)
    {
        cin>>x>>y;
        drn.push_back({{x, y}, i});
    }
    fill_n(aliv, n+5, true);
    sort(drn.begin(), drn.end(), cmp);

    double delta;
    int cnt = 0;
    for (int i = 0; i < n-1; i++)
    {
        //int locI1=drn[i].first.first, locI2 = drn[i+1].first.first;
        //int spdI1 = drn[i].first.second, spdI2=drn[i+1].first.second;
        delta = colid(drn[i].first.first, drn[i].first.second, drn[i+1].first.first, drn[i+1].first.second);
        //cout<<"DELTA:   "<<delta<<"\n";
        //cout<<locI2<<"  "<<locI1<<" "<<spdI1<<" "<<spdI2<<" "<<"\n";
        //if (spdI1!=spdI2) cout<<(locI2-locI1)/(spdI1-spdI2)<<"\n";
        if(delta > 0) {
            col.insert({delta, {i, i+1}});
        }
    }

    while(!col.empty())
    {
        pair<double, pair<int, int>> u;
        u = *col.begin();
        col.erase(col.begin());

        int firD = u.second.first, secD = u.second.second;
        int i_firD = drn[firD].second, i_secD = drn[secD].second;

        if(aliv[i_firD] && aliv[i_secD])
        {
            cnt+=2;
            aliv[i_firD] = false; aliv[i_secD] = false;

            int backD = u.second.first-1, frontD = u.second.second+1;
            if(inrange(backD,frontD))
            {
                int i_backD = drn[backD].second, i_frontD = drn[frontD].second;
                if (aliv[i_backD] && aliv[i_frontD])
                {
                    delta = colid(drn[backD].first.first, drn[backD].first.second, 
                    drn[frontD].first.first, drn[frontD].first.second);
                    //cout<<"DELTA inside:   "<<delta<<"\n";
                    if (delta > 0)
                    {
                        col.insert({delta, {backD, frontD}});
                    }
                } 
            }
        }
    }
    cout<<n-cnt<<"\n";
    for (int i = 0; i < n; i++)
    {
        if (aliv[i])
        {
             cout<<i+1<<" ";
        }
    }
    
}