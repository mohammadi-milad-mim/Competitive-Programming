#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for (auto i=(a); i<(b); ++i)
#define iter(it,c) for (auto it = (c).begin(); it != (c).end(); ++it)
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef long long ll;
const int INF = 2147483647;

int main() {
    int n;
    cin >> n;

    while (n--) {
        int x = 1000000/2,
            y = 1000000/2;
        cout << x << " " << y << endl;
        ll mn;
        if (!(cin >> mn)) {
            return 0;
        }
        if (mn == 0) {
            continue;
        }

        for (int it = 1<<20; it >= 1; it >>= 1) {

            for(bool h : {true, false}){
                int bx = -1,
                    by = -1;
                rep(dx,-1,2) {
                    rep(dy,-1,2) {
                        if (abs(dx) + abs(dy) == 0) continue;
                        if (abs(dx) + abs(dy) == 2) continue;
                        if(h and dx!=0) continue;
                        if(not h and dy!=0) continue;

                        int nx = x + it * dx,
                            ny = y + it * dy;
                        if (!(nx >= 0 && nx <= 1000000 && ny >= 0 && ny <= 1000000)) {
                            continue;
                        }
                        cout << nx << " " << ny << endl;
                        ll d;
                        if (!(cin >> d)) {
                            return 0;
                        }
                        if (d == 0) {
                            goto next;
                        }
                        if (d < mn) {
                            mn = d;
                            bx = nx;
                            by = ny;
                        }
                    }
                }

                if (bx != -1) {
                    x = bx;
                    y = by;
                }
            }
        }
        assert(false);
next:
        continue;
    }

    return 0;
}

