#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    while (n+m)
    {
        int a[n];
        int b[m];
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin>>b[i];
        }
        
        int i=0; int j=0;
        int c=0;
        while (i<n and j<m)
        {
            if (a[i]==b[j])
            {
                c++;
                i++; j++;
            }
            else if (a[i]>b[j])
            {
                j++;
            }
            else
            {
                i++;
            }
        }
        cout<<c<<'\n';
        cin>>n>>m;
    }
}