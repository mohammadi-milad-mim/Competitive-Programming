#include <bits/stdc++.h>


using namespace std;

int main(){
    int t;
    cin>>t;
    int k = 31;
    long long int li[31];
    li[0]=0;
    for (int i = 1; i < k; i++)
    {
        li[i]=(li[i-1]*2)+1;
    }
    int n;
    for (int i = 0; i < t; i++)
    {
        cin>>n;
        cout<<li[n]<<'\n';
    }
    
}