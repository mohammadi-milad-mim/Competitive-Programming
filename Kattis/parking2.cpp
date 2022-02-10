#include<bits/stdc++.h>

using namespace std;

int main(){
    int te;
    cin>>te;
    for (int j=0; j<te; j++){
        int n,t;
        int mi = 100;
        int ma = -1;
        cin>>n;
        int s = 0;
        for (int i=0; i<n; i++){
            cin>>t;
            if (t<mi) mi=t;
            if (t>ma) ma=t;
        }
        cout<<(ma-mi)*2<<'\n';
    }
    
}
