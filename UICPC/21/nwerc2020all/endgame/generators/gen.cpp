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

int n;
set<pair<int,int> > jumps;

int parse(const char *arg) {
    if (strcmp(arg, "n") == 0) {
        return n;
    } else if (strcmp(arg, "-n") == 0) {
        return -n;
    } else {
        return atoi(arg);
    }
}

int rand_int(int a, int b) {
    return rand() % (b - a + 1) + a;
}

bool can_capture(int x0, int y0, int x1, int y1, bool allow_outside=false) {
    if (x0 == x1 && y0 == y1) return true;
    iter(it,jumps) {
        int x = x0 + it->first,
            y = y0 + it->second;
        if (x == x1 && y == y1) {
            return true;
        }
        if (!allow_outside) {
            if (x < 0 || x >= n || y < 0 || y >= n) {
                continue;
            }
        }
        if (jumps.find(make_pair(x1 - x, y1 - y)) != jumps.end()) {
            return true;
        }
    }
    return false;
}

int main(int argc, char *argv[]) {
    srand(atoi(argv[argc-1]));

    n = atoi(argv[1]);

    int mnx = max(-n+1, parse(argv[2])),
        mxx = min(n-1, parse(argv[3])),
        mny = max(-n+1, parse(argv[4])),
        mxy = min(n-1, parse(argv[5]));

    bool alice_valid_moves = strcmp(argv[6], "yes") == 0,
         bob_valid_moves = strcmp(argv[7], "yes") == 0;

    bool alice_capture_bob = strcmp(argv[8], "yes") == 0,
         bob_capture_alice = strcmp(argv[9], "yes") == 0;
    bool alice_capture_bob_outside = strcmp(argv[8], "outside") == 0,
         bob_capture_alice_outside = strcmp(argv[9], "outside") == 0;

    while (true) {
        jumps.clear();
        while (jumps.size() < n) {
            jumps.insert(make_pair(
                        rand_int(mnx, mxx),
                        rand_int(mny, mxy)
                        ));
        }

        int ar, ac;
        int tries = 0;
        while (tries < 1000) {
            ++tries;
            ar = rand() % n;
            ac = rand() % n;
            bool any_valid = false;
            iter(it,jumps) {
                int x = ar + it->first,
                    y = ac + it->second;
                if (0 <= x && x < n && 0 <= y && y < n) {
                    any_valid = true;
                    break;
                }
            }
            if (any_valid == alice_valid_moves) {
                break;
            }
        }
        if (tries == 1000) continue;

        int br, bc;
        tries = 0;
        while (tries < 1000) {
            ++tries;
            br = rand() % n;
            bc = rand() % n;
            if (ar == br && ac == bc) continue;
            bool any_valid = false;
            iter(it,jumps) {
                int x = br + it->first,
                    y = bc + it->second;
                if (0 <= x && x < n && 0 <= y && y < n) {
                    any_valid = true;
                    break;
                }
            }
            if (any_valid == bob_valid_moves) {
                break;
            }
        }
        if (tries == 1000) continue;

        if (can_capture(ar, ac, br, bc) != alice_capture_bob) continue;
        if (can_capture(br, bc, ar, ac) != bob_capture_alice) continue;
        if (alice_capture_bob_outside && !can_capture(ar, ac, br, bc, true)) continue;
        if (bob_capture_alice_outside && !can_capture(br, bc, ar, ac, true)) continue;

        cout << n << endl;
        cout << ar+1 << " " << ac+1 << endl;
        cout << br+1 << " " << bc+1 << endl;
        iter(it,jumps) {
            cout << it->first << " " << it->second << endl;
        }
        break;
    }

    return 0;
}

