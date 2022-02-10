#include<algorithm>
#include<cassert>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<set>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
#define x first
#define y second

bool valid[3][400][400];

int enter_time[2][400];
int leave_time[2][400];

bool overlap(int i) {
	return max(enter_time[0][i], enter_time[1][i])
		< min(leave_time[0][i], leave_time[1][i]);
}

int main() {
	// srand(3141592);

	int n;
	cin >> n;

	vector<int> d(n);
	for (int &x:d) cin >> x;

	vector<int> t[3];
	for (int i=0; i<3; i++) {
		t[i].resize(n);
		for (int &x:t[i]) cin >> x;
	}

	for (auto [a,b] : vector<ii>{{0,1},{1,2},{2,0}}) {
		for (int i = 0; i < n; i++) {

			int curtime = 0;
			for (int loc = i, ln = loc; loc < i + n; loc++) {
				enter_time[0][ln] = curtime;
				curtime += t[a][ln];
				leave_time[0][ln] = curtime;
				curtime += d[ln];

				if (++ln == n) ln = 0;
			}

			for (int j = 0; j < n; j++) {
				curtime = 0;
				for (int loc = j, ln = loc; loc < j + n; loc++) {
					enter_time[1][ln] = curtime;
					curtime += t[b][ln];
					leave_time[1][ln] = curtime;
					curtime += d[ln];

					if (++ln == n) ln = 0;
				}

				valid[3^a^b][i][j] = true;
				for (int loc = 0; loc < n; loc++)
					valid[3^a^b][i][j] &= !overlap(loc);
			}
		}
	}

	for (int a = 0; a < n; a++) {
		for (int b = 0; b < n; b++) {
			for (int c = 0; c < n; c++) {
				if (valid[2][a][b] && valid[0][b][c] && valid[1][c][a]) {
					cout << (a+1) << " " << (b+1) << " " << (c+1) << endl;
					return 0;
				}
			}
		}
	}

	cout << "impossible" << endl;
	return 0;
}
