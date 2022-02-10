#include <bits/stdc++.h>

using namespace std;

int main(){
    int test;
    cin>>test;
    for (int i=0; i<test; i++){
        int num;
        cin>>num;
        long long int lis [num];
        for (int j=0; j<num; j++){
            cin>>lis[j];
        }
        sort(lis, lis+num);
        for (int j=0; j<num-1; j++){
            //cout<<j<<" "<<lis[j]<<" "<<lis[j+1]<<"\n";
            if (lis[j+1]!=lis[j]){
                cout<<"Case #"<<(i+1)<<": "<<lis[j]<<"\n";
                break;
            }
            else{
                if (j!=num-3){
                    j+=1;
                }
                else{
                    cout<<"Case #"<<(i+1)<<": "<<lis[num-1]<<"\n";
                    break;
                }
            }
        }
    }
}