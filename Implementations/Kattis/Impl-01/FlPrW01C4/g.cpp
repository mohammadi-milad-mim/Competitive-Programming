#include <bits/stdc++.h>

using namespace std;

int main(){
    int test;
    cin>>test;
    for (int t=0; t<test; t++){
        int k,n;
        cin>>k>>n;
        long long int s1,s2,s3;
        s1 = ((1+n)*n)/2;
        s2 = ((1+(2*n-1))*n)/2;
        s3 =  ((2+(2*n))*(n))/2;
        cout<<k<<" "<<s1<<" "<<s2<<" "<<s3<<'\n';
    }
}