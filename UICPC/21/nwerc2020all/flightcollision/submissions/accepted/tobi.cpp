#include <bits/stdc++.h>
using namespace std;

struct crash { long long int drones[2], timeNum, timeDen; };
long long int numDrones, nxt[100000], prv[100000], numCrashed, v[100000], x[100000], crashed[100000];
auto cmp = [](crash left, crash right) { return left.timeNum*right.timeDen > right.timeNum*left.timeDen; };
priority_queue<crash, vector<crash>, decltype(cmp)> crashes(cmp);

void insertPotentialCrash(int i, int j) {
	if (i < 0 || j < 0 || v[i] == v[j]) return;
	crash boom;
	boom.drones[0] = i, boom.drones[1] = j;
	boom.timeNum = x[i]-x[j], boom.timeDen = v[j]-v[i];
	if (boom.timeDen < 0) boom.timeDen *= -1, boom.timeNum *= -1;
	if (boom.timeNum >= 0) crashes.push(boom);
}

int main() {
	cin >> numDrones;
	for (int i = 0; i < numDrones; i++) {
		cin >> x[i] >> v[i];
		prv[i] = i-1, nxt[i] = i == numDrones-1 ? -1 : i+1;
		insertPotentialCrash(i-1, i);
	}
	while (!crashes.empty()) {
		crash boom = crashes.top();
		crashes.pop();
		int left = boom.drones[0], right = boom.drones[1];
		if (crashed[left] || crashed[right]) continue;
		crashed[left] = crashed[right] = true;
		numCrashed += 2;
		insertPotentialCrash(prv[left], nxt[right]);
		if (prv[left] != -1) nxt[prv[left]] = nxt[right];
		if (nxt[right] != -1) prv[nxt[right]] = prv[left];
	}
	cout << (numDrones-numCrashed) << endl;
	for (int i = 0; i < numDrones; i++) if (!crashed[i]) cout << (i+1) << " ";
}
