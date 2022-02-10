#include <bits/stdc++.h>

using namespace std;

int main(){
    int c,d;
    cin>>c>>d;
    if (c==d) cout<<0;
    else if (c > d){
        int pdif= (d+360 - c);
        int ndif = (c - d);
        if (ndif == pdif) cout<<180;
        else if (ndif < pdif) cout<<(-1*ndif);
        else cout<<pdif;
    }
    else{
        int pdif = d-c;
        int ndif = (c+360)-d;
        if (ndif == pdif) cout<<180;
        else if (ndif < pdif) cout<<(-1*ndif);
        else cout<<pdif;
    }
}