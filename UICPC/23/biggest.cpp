#include <bits/stdc++.h>
using namespace std;
typedef long double ld;

ld degconv(int d, int m, int s)
{
    ld mi =m/ld(60);
    ld se = s/ld(3600);
    d = ld(d);
    return d+mi+se;
}

int main()
{
    int testCases;
    cin>>testCases;
    for (int tt = 0; tt < testCases; tt++)
    {
        ld r;
        cin>>r;
        int n,d,m,s;
        cin>>n>>d>>m>>s;
        ld deg = degconv(d,m,s);
        set<ld> s_degs;
        ld full = ld(360);
        ld now=0;
        for (int i = 0; i < n; i++)
        {
            if (now >full)
            {
                now-=full;
            }
            cout<<now<<"   ";
            if(s_degs.find(now) != s_degs.end()) break;
            s_degs.insert(now);
            now+=deg;
        }
        //cout<<endl;
        ld maxSlice = 0.0;
        ld sdFirst=0;
        ld sdLast=0;
        ld sdEnd=0;
        ld sli=0;
        int in=0;
        bool first = false;
        for (auto sd: s_degs)
        {
            //cout<<sd<<"     :\n";
            in++;
            if (first)
            {
                sli = sd - sdLast;
            }
            else
            {
                first=true;
                sdFirst = sd;
            }
            
            
            if (sli>maxSlice)
            {
                maxSlice = sli;
            }
            //cout<<sdLast<<"  "<<sd<<"    "<<sli<<"     "<<maxSlice<<endl;
            sdLast=sd;
            sdEnd=sli;
        }
        sli = (360-sdLast)+sdFirst;
        if (sli>maxSlice)
        {
            maxSlice=sli;
        }
        //cout<<maxSlice<<"    "<<endl;
        ld portion = (maxSlice)/ld(360);
        ld pii = (3.14159265358979323846);
        ld r2 = r*r;
        ld res = portion*pii*r2;
        //cout<<M_PI<<"  \n";
        cout << setprecision(6) << fixed << res<<'\n';
    }

}