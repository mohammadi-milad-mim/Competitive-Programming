#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int res=0;
    int n = 10000;
    int i,j,k;
    for (i = 0; i < n; i++)
    {
        for ( j= i+1; j < n; j++)
        {
            for ( k= j+1; k < n; k++)
            {
                res++;
            }
        }
    }
    cout<<res;
}