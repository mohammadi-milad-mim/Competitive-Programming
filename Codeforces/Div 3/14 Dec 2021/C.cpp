#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef vector<lli> vlli;

vlli listofcd(lli a, lli b)
{
    vlli t;
    for(lli i=1; i <= a && i <= b; ++i) 
    {
      if(a%i==0 && b%i==0) 
      {
         t.push_back(i);
      }
    }
    return t;
}


int main()
{
    int T; cin>>T;
    while (T--)
    {
        int n; cin>>n;
        vlli allposs;
        lli nums[n];
        for (int i = 0; i < n; i++)
        {
            cin>>nums[n];
        }
        for (int i = 2; i < n; i++)
        {
            vlli cds = listofcd(nums[i-1],nums[i]);
        }
        cout<<1;
        
    }
    
}