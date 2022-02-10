#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n, m, y;
    unordered_set<int> s;

    cin >> n;
    while (n--) {
        cin >> m >> y;
        s.clear();
        int ma = 0;
        unordered_set<int> s;
        for (int i = 0; i < m; i++) {
            int temp;
            cin >> temp;
            vector<int> v;
            for (auto itr = s.begin(); itr != s.end(); ++itr) {
                if (*itr * temp <= y) {
                    ma = (*itr * temp > ma) ? *itr * temp : ma;
                    v.push_back(*itr * temp);
                }
            }
            s.insert(v.begin(), v.end());
            if (temp <= y) {
                if (temp > ma) {
                    ma = temp;
                }
                s.insert(temp);
            }
        }
        cout << ma << '\n';
    }
    return 0;
}