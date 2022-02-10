#include <bits/stdc++.h>

using namespace std;

int main()
{
    float r,c; cin>>r>>c;
    cout << fixed << setprecision(6) << ((r-c)*(r-c))/(r*r)*100;
}