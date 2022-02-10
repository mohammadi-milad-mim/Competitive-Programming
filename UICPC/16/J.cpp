#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
// std::cout << std::setprecision(3) << std::fixed << doubllle;
typedef unsigned long long int ulli;
// sort(arr, arr + n, greater<int>());
//c = ::tolower(c);
//for (int i = 0; i < s.size(); i++) {
//s[i] = tolower(s[i]);


int main(){
    int n;
    float p;
    cin>>n>>p;
    int costs[n];
    int weights[n];
    vector < pair <int,int> > vect;
    float temp =p;
    int P = int(temp*10000);
    int tep;
    int tem;
    //cout<<n<<" "<<P<<'\n';
    for (int i = 0; i < n; i++) 
    {
        int tem;
        float temp;
        cin>>tem>>temp;
        //cout<<tem<<" "<<temp<<"\n";
        costs[i]=tem;
        tep = int(temp*10000);
        weights[i]=tep;
        //cout<<costs[i]<<" "<<weights[i]<<"\n";
        vect.push_back( make_pair(costs[i],weights[i]) );
    }
    sort(vect.begin(), vect.end());
    for (int i=0; i<n; i++)
        {
            cout << vect[i].first << " "
                << vect[i].second << endl;
        }
    int maxW = 10001;
    int maxN = n+1;

    int f[maxN][maxW];
    for (int i = 0; i < maxN; i++)
        for (int j = 0; j < maxW; j++)
            f[i][j] = 1000000;

    int minW = P;
    int result = 1000000;
    
    f[0][vect[0].second] = vect[0].first;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= maxW; j++) {
            
            f[i][j] = f[i - 1][j];

            if (j - vect[i].second >= 0) {
                if (f[i][j] > f[i - 1][j - vect[i].second] + vect[i].first)
                    f[i][j] = f[i - 1][j - vect[i].second] + vect[i].first;
            }

            if (j >= minW and f[i][j] < result) {
                result = f[i][j];
            }
        }
    }
    cout << result <<'\n';
}