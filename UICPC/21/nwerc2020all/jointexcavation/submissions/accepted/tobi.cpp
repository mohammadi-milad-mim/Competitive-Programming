#include <bits/stdc++.h>
using namespace std;

int c, t, a, b, vis[2000001], leftKid;
vector<int> adj[2000001], mother;
stack<int> s;

void isFair() {
	if (c - (int)mother.size() == 2 * leftKid) {
		cout << mother.size() << " " << leftKid << endl;
		for (auto m : mother) cout << (m+1) << " ";
		cout << endl;
		for (int i = 0; i < c; i++) if (vis[i] == 0) cout << (i+1) << " ";
		cout << endl;
		for (int i = 0; i < c; i++) if (vis[i] == 2) cout << (i+1) << " ";
		cout << endl;
		exit(0);
	}
}

int main() {
	cin >> c >> t;
	for (int i = 0; i < t; i++) {
		cin >> a >> b;
		adj[a-1].push_back(b-1);
		adj[b-1].push_back(a-1);
	}
	isFair();

	s.push(0);
	while (!s.empty()) {
		int node = s.top();
		s.pop();
		if (vis[node] == 2) continue;
		if (++vis[node] == 2) {
			mother.pop_back();
			leftKid++;
			isFair();
		} else {
			s.push(node);
			mother.push_back(node);
			isFair();
			for (auto next : adj[node]) if (vis[next] == 0) s.push(next);
		}
	}

}
