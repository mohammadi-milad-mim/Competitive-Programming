#include <bits/stdc++.h>

using namespace std;

int main(){
    string ad = "ABCABCABCABC";
    string br = "BABCBABCBABC";
    string go = "CCAABBCCAABB";
    string s;
    int n;
    int cad =0, cbr=0, cgo=0;
    cin>>n>>s;
    for (int i=0; i<n; i++){
        if (s[i]==ad[i%12]){
            cad+=1;
        }
        if (s[i]==br[i%12]){
            cbr+=1;
        }
        if (s[i]==go[i%12]){
            cgo+=1;
        }
    }
    int ma = max(cad,cbr);
    ma = max(ma,cgo);
    cout<<ma<<'\n';
    if (cad==ma) cout<<"Adrian"<<'\n';
    if (cbr==ma) cout<<"Bruno"<<'\n';
    if (cgo==ma) cout<<"Goran"<<'\n';
}