#include <bits/stdc++.h>

using namespace std;

int main(){
    int t=1;
    while (true){
        cout<<"Case "<<t<<':'<<'\n';
        int n;
        cin>>n;
        int li[n];
        for (int i=0; i<n;i++ ){
            cin>>li[i];
        }
        int m;
        cin>>m;
        int qu[m];
        for (int i=0; i<m;i++ ) cin>>qu[i];
        for (int q=0; q<m; q++){
            int num = qu[q];
            int su=INT_MAX;
            for (int i=0; i<n; i++){
                for (int j=i+1; j<n; j++){
                    int dif = abs(num-(li[i]+li[j]));
                    su = min(dif,su);
                }
            }
            cout<<"Closest sum to "<<num<<" is "<<su<<"."<<'\n';
        }
    t+=1;
    }
}