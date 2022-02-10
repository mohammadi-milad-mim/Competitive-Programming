#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin>>n;
    
    int c=0;
    for (int i = 0; i < n; i++)
    {
        int t; cin>>t; t--;
        if (t!=i)
        {
            c++;
        }
    }
    if (c==2)
    {
        cout<<"YES";
    }
    else
    {
        cout<<"NO";
    }
    
}