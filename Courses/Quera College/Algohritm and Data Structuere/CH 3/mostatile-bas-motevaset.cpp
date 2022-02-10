#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n; cin>>n;
    int md = 1000000007;
    long long count = 0;
    long long zero = 0;
    for (int i = 1; i < (n/3); i++)
    {
        count = (count+(n-3*i/2) - max(zero,((n/2)-2*i+1))+1)%md;
    }
    cout<<count%md;
}