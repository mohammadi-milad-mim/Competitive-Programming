#include <bits/stdc++.h>

using namespace std;

int main(){
	srand(time(0));
    int test;
    //cin>>test;//1-10
    test = rand()%(10-1+1)+1;  cout<<test<<" ";
    cout<<" --input "<<endl;

    for (int i=1; i<=test; i++){
        int n;
        //cin>>n;//1-800
        n = rand()%(800-1+1)+1;  cout<<n<<" ";
        cout<<" --input "<<endl;

        long long int x[n];
        long long int y[n];
        for (int j=0; j<n; j++){
            //cin>>x[j];//0-100000
            x[j] = rand()%(100000-(-100000)+1)+0;  cout<<x[j]<<" ";
            cout<<" --input "<<endl;

        }
        for (int j=0; j<n; j++){
            //cin>>y[j];//0-100000
            y[j] = rand()%(100000-(-100000)+1)+0;  cout<<y[j]<<" ";
            cout<<" --input "<<endl;

        }
        sort(x,x+n);
        sort(y,y+n);
        long long int s=0;
        for (int j=0; j<n; j++){
            s+=((x[j])*(y[n-1-j]));
        }
        cout<<"Case #"<<i<<": "<<s<<'\n';
    }
}
//num-2 timeout-1000 test2-in00.txt
