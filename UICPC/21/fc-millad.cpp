#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int n;
bool aliv[100005];
vector<pair<pair<int, int>, int>> drn; //loc, v, ind
set<pair<double, pair<int, int>>> col; //xt, ind
bool cmp(pair<pair<int, int>, int> x, pair<pair<int, int>, int> y)
{
    return x.first.first < y.first.first;
}

ld colid(int x, int xt, int y, int yt)
{
    if (yt == xt) return 0;
    return ld(y-x)/ld(xt - yt);
}

bool inrange(int ind1, int ind2)
{
    return ind1 >= 0 && ind2>=0 && ind1 < n && ind2 < n;
}

int findBack(int i)
{
    int t = i-1;
    int indexI;
    while (t>=0)
    {
        indexI = drn[t].second;
        if (aliv[t]) return t;
        t--;
    }
    return -1;
}

int findFront(int i)
{
    int t = i+1;
    int indexI;
    while(t<n)
    {
        indexI = drn[t].second;
        if (aliv[indexI]) return t;
        t++;
    }
    return -1;
}

int main()
{
    
    cin>>n;
    int x, y;
    for (int i = 0; i < n; i++)
    {
        cin>>x>>y;
        drn.push_back({{x, y}, i});
    }
    fill_n(aliv, n+5, true);
    sort(drn.begin(), drn.end(), cmp);

    ld delta;
    int cnt = 0;
    for (int i = 0; i < n-1; i++)
    {
        //int locI1=drn[i].first.first, locI2 = drn[i+1].first.first;
        //int spdI1 = drn[i].first.second, spdI2=drn[i+1].first.second;
        delta = colid(drn[i].first.first, drn[i].first.second, drn[i+1].first.first, drn[i+1].first.second);
        //cout<<"DELTA:   "<<delta<<"\n";
        //cout<<locI2<<"  "<<locI1<<" "<<spdI1<<" "<<spdI2<<" "<<"\n";
        //if (spdI1!=spdI2) cout<<(locI2-locI1)/(spdI1-spdI2)<<"\n";
        if(delta > 0.0) {
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
            int backD = findBack(firD);
            int frontD = findFront(secD);
            if (backD!=-1 && frontD!=-1)
            {
                delta = colid(drn[backD].first.first, drn[backD].first.second, 
                drn[frontD].first.first, drn[frontD].first.second);
                //cout<<"DELTA inside:   "<<delta<<"\n";
                if (delta > 0.0)
                {
                    col.insert({delta, {backD, frontD}});
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