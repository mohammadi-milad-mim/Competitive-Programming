#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    for(int c1 = 0; c1 < n; c1++){
        cin >> A[c1];
    }
    sort(A.begin(), A.end());
    vector<int> ANS;
    int l = 0;
    int r = n-1;
    while(l <= r){
        if((r-l)%2 == 1){
            ANS.push_back(A[r]);
            r--;
        }
        else{
            ANS.push_back(A[l]);
            l++;
        }
    }
    reverse(ANS.begin(), ANS.end());
    for(int c1 = 0; c1 < n; c1++){
        cout << ANS[c1] << " ";
    }cout << "\n";

    return 0;
}

