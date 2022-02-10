#include <bits/stdc++.h>
using namespace std;
int mp[100][100];
int main()
{
    int n; cin>>n;
    int x,y;
    char d,p;
    int di;
    for (int i = 0; i < n; i++)
    {
        cin>>x>>y>>d;
        if (d=='U') {di=1; p='V';}
        else if (d=='D') {di=-1; p='V';}
        else if (d=='L') {di=-1; p='H';}
        else {di=1; p='H';}
        
    }
    
}