#include <bits/stdc++.h>

using namespace std;

bool compare(int i1, int i2)
{
    return (i1 > i2);
}
int main(){
    int N,M,K;
    cin>>N>>M>>K;
    int mk = M+K;
    int p[N],c[mk];
    int t;
    for (int i = 0; i < N; i++){
        cin>>t;
        t=pow(t,2);
        p[i]=t*2;
    }
    for (int i = 0; i < M; i++){
        cin>>t;
        t=pow(t,2);
        c[i]=t*2;
    }
    for (int i = M; i < mk; i++){
        cin>>t;
        t=pow(t,2);
        c[i]=t;
    }
    sort(p,p+N,compare);
    sort(c,c+mk,compare);
    int j=0;
    int co=0;
    for (int i = 0; i <N; i++)
    {
        while (j<mk and p[i]<=c[j]){
            j+=1;
        }
        if (j!=mk){
            co+=1;
            j+=1;
        }
        else break;
    }
    cout<<co;
    
    
}