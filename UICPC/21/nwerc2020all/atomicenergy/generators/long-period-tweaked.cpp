#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<ll>;

constexpr ll MAX_A = 1000000000LL;
constexpr ll MAX_K = 1000000000LL;

int main(int argc, char *argv[]) {

	int N = stoi(argv[1]);
	int Q = stoi(argv[2]);

	int MIN_LAST = stoi(argv[3]);
	int MIN_PERIOD = stoi(argv[4]);

	srand(stoi(argv[5]));

	while (true) {
		vi a(N+1);
		for (int i = 1; i <= N; ++i)
			a[i] = rand() % MAX_A + 1LL;

		int m = 1;
		for (int i = 1; i <= N; ++i)
			if (a[i] * m < a[m] * i)
				m = i;
		if (m < MIN_PERIOD) continue;

		a.resize(N*N+1);
		int b = m;
		vi jump;
		for (int i = N+1; i <= N*N; ++i) {
			a[i] = a[1] + a[i-1];
			for (int j = 2; j <= N; ++j)
				a[i] = min(a[i], a[j] + a[i-j]);
			if (a[i] < a[m] + a[i-m])
				jump.push_back(i), b = i;
		}
		if (b < MIN_LAST) continue;

		cout << N << ' ' << Q << '\n';
		for (int i = 1; i <= N; ++i)
			cout << a[i] << " \n"[i==N];
		for (int k = 0; k < Q; ++k) {
			int i = rand() % (int)jump.size();
			cout << jump[i] + m * (rand() % ((MAX_K - jump[i])/m)) << '\n';
		}
		cout << flush;
		break;
	}
}
