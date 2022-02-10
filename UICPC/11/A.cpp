#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
vector<int> sq;
bool cmp(pair<int, int> a, pair<int, int> b){
    if (a.first == b.first) return a.second > b.second;
    else return a.first < b.first;
}
void LIS(int* a, int size, pair<int, int>* next) {
    int ans = 1, a2=-1;
    int* b = new int[size];
    for (int i = 0; i < size; i++) {
        b[i] = 1;
        next[i] = {-1 , i};
    }

    for (int i = size - 2; i >= 0; i--) {
        for (int j = i + 1; j < size; j++) {
            if (a[i] <= a[j]) {
                b[i] = b[j] + 1;
                next[i] = {b[j] , j};
                break;
            }
        }
        if (b[i] > ans) {
            ans = b[i];
            a2 = i;
        }
    }

}

int main()
{
	int t, c=0;
	cin >> t;
    vector<pair<int,int>> out;
	while (t--) {
        c++;
        int n, m;
        cin >> n >> m;
        pair<int, int>* ps = new pair<int, int>[m];
        pair<int, int>* b = new pair<int, int>[m];
        for (int i = 0; i < m; i++) {
            int x;
            cin >> x;
            b[i] = ps[i] = { x,i };
        }
        sort(b, b + m,cmp);
        int count = 1;
        for (int i = 0; i < m-1; i++) {
            if (b[i].second > b[i + 1].second) {
                break;
            }
            else
                count++;
        }
        ////
        //cout <<  m - count << endl;
        ////
        out.push_back({ n, m - count });

	}
    for (auto it : out) {
        cout << it.first << " " << it.second << endl;
    }
}