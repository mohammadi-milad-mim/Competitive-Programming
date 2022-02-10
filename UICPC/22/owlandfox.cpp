#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin>>n;
    while (n--)
    {
        int num; cin>>num;
        int rem;
        int step=10;
        while (true)
        {
            rem = num%step;
            if (rem || rem==num)
            {
                cout<<(num-(step/10))<<'\n';
                break;
            }
            step*=10;
        }
    }
}