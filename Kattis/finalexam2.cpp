#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    char t1,t2;
    cin>>n;
    int s = 0;
    cin>>t1;
    for (int i=0; i<n-1; i++){
        //cout<<t1<<" "<<t2<<'\n';
        cin>>t2;
        if (t2==t1) s+=1;
        t1=t2;
    }
    cout<<s;
}
