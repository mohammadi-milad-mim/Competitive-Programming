#include <bits/stdc++.h>

using namespace std;

int main(){
   string s;
   cin>>s;
   int n = s.length();
   cout<<s[0];
   for (int i=0; i<n; i++){
       if ((s[i]=='-') && (i!=n-1)){
           cout<<s[i+1];
       }
   }
}