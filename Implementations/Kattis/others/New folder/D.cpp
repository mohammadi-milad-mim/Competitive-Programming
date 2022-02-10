#include <bits/stdc++.h>

using namespace std;


char inttochar(int a, int r){
    if (a==95){
        a=27+64;
    }
    else if (a==46){
        a=28+64;
    }
    int t = ((a-64)+r)%28;
    if (t==0) return '.';
    if (t==27) return '_';
    else return char(t+64);
}


int main(){
    int r;
    cin>>r;
    while (r!=0){
        string st;
        string tem = "";
        cin>>st;
        //cout<<st<<endl;
        reverse(st.begin(), st.end());
        for (int i=0; i<st.length(); i++){
            //cout<<st[i]<<endl;
            //cout<<(inttochar(int(st[i]),r))<<endl;
            tem.push_back(inttochar(int(st[i]),r));
        }
        
        cout<<tem<<'\n';
        cin>>r;
    }
}