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

vi adj[1000100];
int color[1000100];
vi path;
int a = 0, b = 0;
int n;

void check() {
    int c = n - a - b;
    if (a == c) {
        cout << b << " " << a << endl;
        iter(it,path) {
            cout << *it+1 << " ";
        }
        cout << endl;
        rep(i,0,n) {
            if (color[i] == 0) {
                cout << i+1 << " ";
            }
        }
        cout << endl;
        rep(i,0,n) {
            if (color[i] == 2) {
                cout << i+1 << " ";
            }
        }
        cout << endl;
    }
}

void dfs(int v) {
    if (color[v] != 0) {
        return;
    }

    path.push_back(v);
    color[v] = 1;
    b++;
    check();

    iter(it,adj[v]) {
        dfs(*it);
    }

    color[v] = 2;
    b--;
    a++;
    path.pop_back();
    check();
}

int main() {
    memset(color, 0, sizeof(color));

    int m;
    cin >> n >> m;

    rep(i,0,m) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    check();
    dfs(0);

    return 0;
}

