#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//ll AdjMat[505][505];


int main()
{
    int t;
    //cin >> t;
    while (cin >> t) {
        int num = t;
        double mx[num][num];
        map<string, int> MAP;
        memset(mx, INT_MAX, sizeof(mx));
        if (!t) break;

        MAP.clear();
        for (int i = 0; i < t; i++) {
            string s;
            cin >> s;
            MAP[s] = i;
        }
        int n;
        cin >> n;
        while (n--) {
            string a, b, l;
            cin >> a >> b >> l;
            int ia = MAP[a];
            int ib = MAP[b];
            int x = 0, y = 0;
            int i;
            for (i = 0; i < l.size(); i++) {
                if (l[i] == ':')
                    break;
                x = x * 10 + stoi(l.substr(i, 1));
            }
            i++;
            while (i < l.size()) {
                y += y * 10 + stoi(l.substr(i, 1));
                i++;
            }
            //cout << x << " " << y << endl;
            double d = double(y) / double(x);
            d = -1*log(d);
            mx[ia][ib] = d;
        }

        //FW
        for (int k = 0; k < t+1; k++)
            for (int i = 0; i < t+1; i++)
                for (int j = 0; j < t+1; j++)
                    mx[i][j] = min(mx[i][j], mx[i][k] + mx[k][j]);

        bool f = false;
        for (int i = 0; i < t; i++)
        {
            if(mx[i][i] < INT_MAX){
                if(mx[i][i] < 0){
                    f = true;
                    break;
                }
            }
        }
        if(f) cout<<"Arbitrage\n";
        else cout<<"Ok\n";
    }

    /*for (int i = 1; i < n+1; i++){
        for (int j = 1; j < n+1; j++){
            cout<<AdjMat[i][j]<<" ";
        }cout<<endl;
    }*/

}