#include <bits/stdc++.h>

using namespace std;

int main()
{
    float c; cin>>c;
    int l; cin>>l;
    float su=0;
    float wi,li;
    for (int i = 0; i < l; i++)
    {
        cin>>wi>>li;
        su+=(li*wi)*c;
    }
    cout << fixed << setprecision(6) << su;
    
}