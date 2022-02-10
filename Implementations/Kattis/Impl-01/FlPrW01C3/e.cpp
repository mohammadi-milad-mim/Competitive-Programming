#include <bits/stdc++.h>

using namespace std;

int main(){
    int test;
    cin>>test;//1-10
    for (int i=1; i<=test; i++){
        int n;
        cin>>n;//1-800
        long long int x[n];
        long long int y[n];
        for (int j=0; j<n; j++){
            cin>>x[j];//0-100000
        }
        for (int j=0; j<n; j++){
            cin>>y[j];//0-100000
        }
        sort(x,x+n);
        sort(y,y+n);
        long long int s=0;
        for (int j=0; j<n; j++){
            s+=((x[j])*(y[n-1-j]));
        }
        cout<<"Case #"<<i<<": "<<s<<'\n';
    }
}
//num-2 timeout-1000 test2-in00.txt