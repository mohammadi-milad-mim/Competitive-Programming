#include <bits/stdc++.h>

using namespace std;

int main(){
    int m =0;
    cin>>m;
    char l;
    string s;
    pair<char,pair<int,pair<int,int>>> THE;
    vector<THE> vec;
    int t=0, sol=0;
    while (m!=-1){
        cin>>l>>s;
        for (auto ii: vec){
            if (ii.first == l){
                if (s=="right"){
                    ii.second.first=1;
                    ii.second.second.first=m;
                }
                else{
                    if (ii.second.first!=1){
                        ii.second.first=0;
                    }
                    ii.second.second.second+=1;
                }
                break;
            }
            else{
                if (s=="right"){
                    p = make_pair(l,(1,(m,0)));
                    vec.push_back();
                }
                
            }
        }
    }
}