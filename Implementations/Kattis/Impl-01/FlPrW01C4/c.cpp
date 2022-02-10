#include <bits/stdc++.h>

using namespace std;

int main(){
    string line;
    int j=0;
    while (getline(cin, line)){
        j++;
        vector<int> myVector;
        istringstream os(line);
        int i;
        while(os >> i)
            myVector.push_back(i);
        sort(myVector.begin()+1, myVector.end());
        int nu=myVector[0];
        cout<<"Case "<<j<<": "<<myVector[1]<<" "<<myVector[nu]<<" "<<myVector[nu]-myVector[1]<<'\n';
    }
}