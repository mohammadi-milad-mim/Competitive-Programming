#include <bits/stdc++.h>

using namespace std;

int main(){
    int l,c;
    int ter = 0;
    int rej = 0;
    cin>>l>>c;
    for (int i=0; i<c; i++){
        string s;
        int t;
        cin>>s>>t;
        if (s=="enter"){
            if ((ter + t)<=l){
                ter+=t;
            }
            else rej+=1;
        }
        else ter-=t;
    }
    cout<<rej;
}