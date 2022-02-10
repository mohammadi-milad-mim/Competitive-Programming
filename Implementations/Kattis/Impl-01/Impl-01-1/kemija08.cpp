#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    string res="";
    getline(cin, s);
    int i=0;
    for (int i=0; i<s.length(); i++){
        if (s[i]=='a' or s[i]=='e' or s[i]=='i' or s[i]=='o' or s[i]=='u'){
            res+=s[i];
            i+=2;
        }
        else{
            res+=s[i];
        }
    }
    cout<<res;
}