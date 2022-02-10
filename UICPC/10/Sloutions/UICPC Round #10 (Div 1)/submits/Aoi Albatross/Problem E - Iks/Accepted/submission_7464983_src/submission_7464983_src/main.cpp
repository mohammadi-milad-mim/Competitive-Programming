#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAX = 1000002;
int dp[MAX][102];
int arr[MAX];

void pre() {
    int j = 2;
    memset(arr, 0, sizeof(arr));
    while (j <= sqrt(MAX)) {
        if (!arr[j]) {
            int k = 2;
            while (k * j < MAX) {
                arr[k * j] = true;
                k++;
            }
        }
        j++;
    }
}

int main() {
    pre();
    int l = 0;
    int ans = 0;
    for (int i = 2; i < MAX; ++i) {
        if (!arr[i]) {
            dp[l][0] = i;
            l++;
        }
    }

    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int temp;
        cin >> temp;
        int k = 0;
        while (temp != 1) {
            if (temp % dp[k][0] == 0) {
                temp /= dp[k][0];
                dp[k][i]++;
            }
            else {
                k++;
            }
        }
    }

    int g = 1;
    for (int i = 0; i < MAX; ++i) {
        int temp = 0;
        for (int j = 1; j <= n; ++j) {
            temp += dp[i][j];
        }
        int z = temp / n;
        g = g * pow(dp[i][0], z);
        for (int j = 1; j <= n; ++j) {
            if (dp[i][j] < z) {
                ans += z - dp[i][j];
            }
        }
    }

//    for (int i = 0; i < 10; ++i) {
//        for (int j = 0; j <= n; ++j) {
//            cout << dp[i][j] << '\t';
//        }
//        cout << endl;
//    }

    cout << g << ' ' << ans << endl;
}