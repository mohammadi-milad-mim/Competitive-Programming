#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; cin>>n;
    bool exis[n+1]; fill_n(exis,n+1,true);
    exis[0]=false;
    int t=5;
    int step=5;
    int now=0;
    exis[step]=false;
    int allc=1;
    while (allc<n-1)
    {
        now=0;
        while (now<5)
        {
            step=(step+1)%(n+1);
            if (exis[step])
            {
                now+=1;
            }
        }
        exis[step]=false;
        allc+=1;
    }
    for (int i = 0; i < n+1; i++)
    {
       if (exis[i])
       {
           cout<<i;
       }
    }
}