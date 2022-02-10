#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,b; cin>>a>>b;
    int su=0;
    if (b%2==0)
    {
        if (a%2!=0)
        {
            su+=b;
        }
    }
    else
    {
        su+=a;
        if (a%2!=0)
        {
            su-=b;
        }
    }
    cout<<su;
}