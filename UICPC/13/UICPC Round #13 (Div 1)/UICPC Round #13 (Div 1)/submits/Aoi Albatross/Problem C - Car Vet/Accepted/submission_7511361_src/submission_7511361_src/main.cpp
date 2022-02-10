#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mx = 260;
int arr[mx][mx];
bool moved[mx * mx];
int n, m;
int dx, dy;
ll ansSize = INT_MAX;
vector<int> ans;

bool ir(int a, int b) {
    return (a >= 0 && a < n && b >= 0 && b < m);
}

void solve(int x, int y, vector<int> moves) {
    if (x == dx && y == dy) {
        if (moves.size() < ansSize) {
            ansSize = moves.size();
            ans = moves;
        }
        else if (moves.size() == ansSize) {
            bool better = false;
            for (int i = 0; i < moves.size(); ++i) {
                if (moves[i] < ans[i]) {
                    better = true;
                    break;
                }
            }
            if (better)
                ans = moves;
        }
    }

    if (ir(x - 1, y) && ir(x - 2, y) && arr[x - 1][y] == arr[x - 2][y] && arr[x - 1][y] != -2) {
        if (!moved[arr[x - 2][y]]) {
            moved[arr[x - 2][y]] = true;
            arr[x][y] = arr[x - 2][y];
            arr[x - 2][y] = -1;
            moves.push_back(arr[x][y]);
            solve(x - 2, y, moves);
            arr[x - 2][y] = arr[x][y];
            arr[x][y] = -1;
            moves.pop_back();
            moved[arr[x - 2][y]] = false;
        }
    }
    if (ir(x + 1, y) && ir(x + 2, y) && arr[x + 1][y] == arr[x + 2][y] && arr[x + 1][y] != -2) {
        if (!moved[arr[x + 2][y]]) {
            moved[arr[x + 2][y]] = true;
            arr[x][y] = arr[x + 2][y];
            arr[x + 2][y] = -1;
            moves.push_back(arr[x][y]);
            solve(x + 2, y, moves);
            arr[x + 2][y] = arr[x][y];
            arr[x][y] = -1;
            moves.pop_back();
            moved[arr[x + 2][y]] = false;
        }
    }
    if (ir(x, y - 1) && ir(x, y - 2) && arr[x][y - 1] == arr[x][y - 2] && arr[x][y - 1] != -2) {
        if (!moved[arr[x][y - 2]]) {
            moved[arr[x][y - 2]] = true;
            arr[x][y] = arr[x][y - 2];
            arr[x][y - 2] = -1;
            moves.push_back(arr[x][y]);
            solve(x, y - 2, moves);
            arr[x][y - 2] = arr[x][y];
            arr[x][y] = -1;
            moves.pop_back();
            moved[arr[x][y - 2]] = false;
        }
    }
    if (ir(x, y + 1) && ir(x, y + 2) && arr[x][y + 1] == arr[x][y + 2] && arr[x][y + 1] != -2) {
        if (!moved[arr[x][y + 2]]) {
            moved[arr[x][y + 2]] = true;
            arr[x][y] = arr[x][y + 2];
            arr[x][y + 2] = -1;
            moves.push_back(arr[x][y]);
            solve(x, y + 2, moves);
            arr[x][y + 2] = arr[x][y];
            arr[x][y] = -1;
            moves.pop_back();
            moved[arr[x][y + 2]] = false;
        }
    }
}

int main() {
    int tx, ty;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> arr[i][j];
            if (arr[i][j] == -1) {
                tx = i; ty = j;
            }
        }
    }
    cin >> dx >> dy;
    dx--;dy--;

    vector<int> vc;
    solve(tx, ty, vc);
    if (ansSize != INT_MAX) {
        for (auto t : ans) {
            cout << t << ' ';
        }
        cout << endl;
    }
    else {
        cout << "impossible" << endl;
    }
}
