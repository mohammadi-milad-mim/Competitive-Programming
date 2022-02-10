#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[7];
    int t; cin>>t;
    while (t--)
    {
       for (int i = 0; i < 7; i++)
       {
           cin>>a[i];
       }
       if (a[0]+a[1]==a[2])
       {
           cout<<a[0]<<" "<<a[1]<<" "<<a[3]<<'\n';
       }
       else
       {
           cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<'\n';
       }
    }
    
}