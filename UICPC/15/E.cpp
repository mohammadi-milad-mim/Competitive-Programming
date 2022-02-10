#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, e=0;
    cin>>n;
    unsigned long long int tem,c=0,s=0;
    for (int i=0; i<n; i++){
        cin >>tem;
        if (i==0){
            c=tem;
            e+=1;
        }
        else{
            s+=tem;
            if (s>=c){
                e+=1;
                c=s;
                s=0;
            }
        }
    }
    cout<<e;
}