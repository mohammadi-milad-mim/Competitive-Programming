#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin>>t;
    int arr[6][2]={{1,0},{1,1},{-1,1},{-1,0},{-1,1},{1,-1}};
    while (t--)
    {
        string s; cin>>s;
        int ver=0,horz=0;
        int A=0,B=0,C=0,D=0,E=0,F=0;
        for (int i = 0; i < s.length(); i++)
        {
            char t = s[i];
            if (t=='A') A++;
            else if (t=='B') B++;
            else if (t=='C') C++;
            else if (t=='D') D++;
            else if (t=='E') E++;
            else if (t=='F') F++;
        }
        B+=C; D+=C;
        F+=E; D+=E;
        A-=D;
        int mi_BF = min(B,F);
        B-=mi_BF; F-=mi_BF; A+=mi_BF;
        if (A>=0) {cout<<B+F+A<<"\n";}
        else {
            A*=-1;
            cout<<max(B+F,A)<<"\n";
            }
        
    }
    
}