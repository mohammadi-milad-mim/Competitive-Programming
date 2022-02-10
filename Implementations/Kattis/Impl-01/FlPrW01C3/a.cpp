#include <bits/stdc++.h>


using namespace std;

int main(){
    string s, t="";
    cin>>s;
    int n = s.length();
    for (int i=0; i<n-1; i++){
        if (s[i]!=s[i+1]){
            t+=s[i];
        }
    }
    int n2 = t.length();
    if (t[n2-1]!=s[n-1]){
        t+=s[n-1];
    }
    cout<<t;
}