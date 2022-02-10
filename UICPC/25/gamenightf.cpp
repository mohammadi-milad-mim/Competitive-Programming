#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n; cin>>n;
    int n2 = 2*n;
    string s; cin>>s;
    s+=s;
    int An[n2],Bn[n2],Cn[n2];
    int cA,cB,cC;
    if (s[0]=='A')
    {
        cA=1,cB=0,cC=0;
    }
    else if (s[0]=='B')
    {
        cA=0,cB=1,cC=0;
    }
    else if (s[0]=='C')
    {
        cA=0,cB=0,cC=1;
    }
    An[0]=cA,Bn[0]=cB,Cn[0]=cC;

    for (int i = 1; i < n2; i++)
    {
        An[i]=An[i-1],Bn[i]=Bn[i-1],Cn[i]=Cn[i-1];
        if (s[i]=='A')
        {
            cA++;
            An[i]++;
        }
        else if (s[i]=='B')
        {
            cB++;
            Bn[i]++;
        }
        else if (s[i]=='C')
        {
            cC++;
            Cn[i]++;
        }
    }
    cA/=2,cB/=2,cC/=2;
    // for ABC
    int nA,nB,nC;
    int p1=cA-1;
    int p2 = p1+cB;
    int p3= p2+cC;
    nA = An[p1];
    nB = Bn[p2] - Bn[p1];
    nC = Cn[p3] - Cn[p2];
    int rights = (cA-nA) + (cB-nB) + (cC-nC);
    int res = rights;
    int mi1 = res;
    int ps;
    for (int i = 0; i < n; i++)
    {
       ps = i;
       p1=ps+cA;
       p2=p1+cB;
       p3=p2+cC;
       
       nA = An[p1]-An[ps];
       nB = Bn[p2] - Bn[p1];
       nC = Cn[p3] - Cn[p2];

       rights = (cA-nA) + (cB-nB) + (cC-nC);
       res = rights;
       mi1 = min(mi1,res);
    }

    //for ACB
    p1=cA-1;
    p2 = p1+cC;
    p3= p2+cB;
    nA = An[p1];
    nC = Cn[p2] - Cn[p1];
    nB = Bn[p3] - Bn[p2];
    rights = (cA-nA) + (cC-nC) + (cB-nB);
    res = rights;
    int mi2 = res;
    for (int i = 0; i < n; i++)
    {
       ps = i;
       p1=ps+cA;
       p2=p1+cC;
       p3=p2+cB;
       
       nA = An[p1]-An[ps];
       nC = Cn[p2] - Cn[p1];
       nB = Bn[p3] - Bn[p2];

       rights = (cA-nA) + (cC-nC) + (cB-nB);
       res = rights;
       mi2 = min(mi2,res);
    }
    cout<<min(mi1,mi2);
}