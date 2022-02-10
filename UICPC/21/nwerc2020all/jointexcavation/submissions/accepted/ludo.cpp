#include<algorithm>
#include<bitset>
#include<cassert>
#include<climits>
#include<iostream>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;

const int MAXN = 200 * 1001;

int n, m;
vi E[MAXN];

// parent node
int par[MAXN];
// size of the subtree:
int subsz[MAXN] = {};

void dfs1(int u, int v) {
	subsz[v] = 1;
	for (int w : E[v]) {
		if (subsz[w] == 0) {
			par[w] = v;
			dfs1(v, w);
			subsz[v] += subsz[w];
		}
	}
}

vi p, child[2];

void paint(int v, int c) {
	child[c].push_back(v);
	for (int w : E[v])
		if (par[w] == v)
			paint(w, c);
}

void dfs2(int v, int cur_diff) {
	if (subsz[v] == abs(cur_diff)) {
		paint(v, cur_diff > 0 ? 0 : 1);
		return;
	}

	p.push_back(v);
	vector<ii> downs;

	for (int w : E[v])
		if (par[w] == v)
			downs.emplace_back(subsz[w], w);
	sort(begin(downs), end(downs));

	if (downs.empty()) {
		assert(cur_diff == 0);
		return;
	}

	int w = downs.back().second;
	for (int i=0; i+1 < (int) downs.size(); i++) {
		if (cur_diff >= 0) {
			cur_diff -= downs[i].first;
			paint(downs[i].second, 0);
		} else {
			cur_diff += downs[i].first;
			paint(downs[i].second, 1);
		}
	}

	dfs2(w, cur_diff);
}

ostream& operator<<(ostream &out, const vi &v) {
	for (int i=0; i < (int) v.size(); i++) {
		if (i) out << ' ';
		out << v[i];
	}
	return out << endl;
}

int main() {
	srand(3141592);

	cin >> n >> m;
	for (int i=0; i<m; i++) {
		int x, y;
		cin >> x >> y;
		E[x].push_back(y);
		E[y].push_back(x);
	}

	int root = 1 + (rand() % n); // in fact, not needed :)
	par[root] = root; // fake parent

	// determine tree structure (removing edges that give a cycle) and subtree sizes.
	dfs1(root, root);
	// find what path mother walks.
	dfs2(root, 0);

	cout << p.size() << " " << (n - p.size()) / 2 << endl << p << child[0] << child[1];
	return 0;
}
