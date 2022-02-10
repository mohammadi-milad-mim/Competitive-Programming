#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    string blank;
    for (int i = 0; i < t; i++)
    {
        //getline(cin,b);
        int Ng,Nm;
        cin>>Ng>>Nm;
        int g[Ng];
        int m[Nm];
        for (int j = 0; i < Ng; j++)
        {
            cin>>g[j];
        }
        for (int j = 0; i < Ng; j++)
        {
            cin>>m[j];
        }
        sort(g,g+Ng);
        sort(m,m+Nm);
        int gg=0, mm=0;
        while (gg<Ng and mm<Nm )
        {
            if (m[mm]<=g[gg])
            {
                mm++;
            }
            else
            {
                gg++;
            }
        }
        if (gg==Ng)
        {
            cout<<"MechaGodzilla"<<"\n";
        }
        else if (mm==Nm)
        {
            cout<<"Godzilla"<<"\n";
        }
    }
    
}