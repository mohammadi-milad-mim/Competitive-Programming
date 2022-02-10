#include <vector>
#include <set>
#include <iostream>
using namespace std;
#define rep(i,a,b) for (auto i=(a); i<(b); ++i)
#define iter(it,c) for (auto it = (c).begin(); it != (c).end(); ++it)
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef long long ll;
const int INF = 2147483647;

int n;
set<ii> moves;
bool jump_from(int x1, int y1, int x2, int y2) {
    iter(it,moves) {
        ii pos(x1 + it->first, y1 + it->second);
        if (1 <= pos.first && pos.first <= n && 1 <= pos.second && pos.second <= n) {
            ii delta(x2 - pos.first, y2 - pos.second);
            if (delta == ii(0,0) || moves.find(delta) != moves.end()) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    cin >> n;

    int ar, ac, br, bc;
    cin >> ar >> ac >> br >> bc;

    rep(i,0,n) {
        int ri, ci;
        cin >> ri >> ci;
        moves.insert(ii(ri,ci));
    }

    if (jump_from(ar,ac, br,bc)) {
        cout << "Alice wins" << endl;
        return 0;
    }

    for (int x = n; x >= 1; x--) {
        rep(y,1,n+1) {
            if (x == br && y == bc) continue;
            if (!jump_from(br,bc, x,y)) {
                cout << "tie " << x << " " << y << endl;
                return 0;
            }
        }
    }

    cout << "Bob wins" << endl;

    return 0;
}

