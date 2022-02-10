#include <bits/stdc++.h>

using namespace std;

int main(){
    int w,p;
    cin>>w>>p;
    int li[p+2];
    int dp[w+1];
    set<int, greater<int> > s1;
    li[0]=0;
    for (int i=0; i<p; i++){
        cin>>li[i+1];
    }
    li[p+1]=w;
    int t;
    for (int i=0; i<p+2; i++){
        for (int j=i+1; j<p+2; j++){
                t = li[j]-li[i];
                s1.insert(t);
        }
    }
    set<int> s2(s1.begin(), s1.end());
    set<int, greater<int> >::iterator itr;
    for (itr = s2.begin(); itr != s2.end(); itr++){
        cout << *itr<<" ";
    }
}