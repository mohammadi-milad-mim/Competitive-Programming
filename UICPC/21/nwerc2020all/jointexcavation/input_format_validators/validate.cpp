#include <bits/stdc++.h>
using namespace std;

const long long MAX_H = 2 * 100 * 1000;
const long long MAX_T = 2 * 100 * 1000;

void fill_DFS(const vector<set<long long>> &graph, const long long index, vector<bool> &vis) {
	vis[index] = true;
	for(const long long next : graph[index]) {
		if(!vis[next]) {
			fill_DFS(graph, next, vis);
		}
	}
}

int main() {
  long long h, t;
	set<pair<long long, long long>> tunnels;
	vector<set<long long>> graph;
  if(!(cin >> h >> t)) {
		std::cerr << "Not enough input" << std::endl;
		return 43;
	}
  if(h < 1 || MAX_H < h || t < 0 || MAX_T < t) {
		std::cerr << "Number of halls or tunnels out or range" << std::endl;
		return 43;
	}
	graph.resize(h + 1);
  for(size_t i = 0; i < t; ++i) {
    long long a, b;
    if(!(cin >> a >> b)){
			std::cerr << "Not enough tunnels" << std::endl;
			return 43;
		}
    if(a == b){
			std::cerr << "Selfloop" << std::endl;
			return 43;
		}
		if(a > b) swap(a,b);
		if(a < 1 || h < b) {
			std::cerr << "Halls IDs out of range (" << a << " , " << b << ")" << std::endl;
			return 43;
		}
		tunnels.insert({a,b});
		graph[a].insert(b);
		graph[b].insert(a);
  }
  char foo;
  if(cin >> foo) {
		std::cerr << "Extra input" << std::endl;
		return 43;
	}
	if(tunnels.size() != t) {
		std::cerr << "Multiple extra tunnels" << std::endl;
		return 43;
	}

	vector<bool> vis(h + 1, false);
	fill_DFS(graph, 1, vis);
	for(size_t i = 1; i <= h; ++i) {
		if(!vis[i]) {
			std::cerr << "(" << i << ") never visited" << std::endl;
			return 43;
		}
	}
  return 42;
}
