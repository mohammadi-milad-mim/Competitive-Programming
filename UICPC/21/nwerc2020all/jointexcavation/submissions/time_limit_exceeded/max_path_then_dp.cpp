/**
 * This submission uses random paths by choosing a random starting point and extending it in both direction
 * as long as possible. Draws a new random path if remaining nodes cannot be divided into two groups.
 *
 * TLE because of unlikeliness to find good path.
 */



#include <deque>
#include <iostream>
#include <random>
#include <unordered_set>
#include <vector>

std::vector<std::vector<std::size_t>> graph, components;
std::vector<std::size_t> pool, A, B;
std::size_t c;
std::mt19937 rng;
std::deque<std::size_t> path;
std::vector<bool> visited;



void create_path() {
	std::size_t start = rng() % c;
	bool forward = true;
	path.push_back(start);
	// It is highly unlikely we draw the real start or end of a path
	// => Assume start is in middle of path
	do {
		std::size_t cur, next = start;
		do {
			if(next != start) {
				if(forward) {
					path.push_back(next);
				} else {
					path.push_front(next);
				}
			}
			visited[next] = true;
			cur = next;
			next = c;
			pool.clear();
			for(std::size_t neigh : graph[cur]) {
				if(!visited[neigh])
					pool.push_back(neigh);
			}
			if(pool.size()) {
				next = pool[rng() % pool.size()];
			}
		} while(next != c);
		forward = !forward;
	} while(!forward);
}

void DFS_helper(std::size_t elem, std::vector<std::size_t> &component) {
	visited[elem] = true;
	component.push_back(elem);
	for(std::size_t neigh : graph[elem]) {
		if(!visited[neigh]) {
			DFS_helper(neigh, component);
		}
	}
}

void calc_components() {
	for(std::size_t i = 0; i < c; ++i) {
		if(!visited[i]) {
			components.emplace_back();
			DFS_helper(i, components.back());
		}
	}
}

bool dp_helper(std::size_t id, std::size_t rem, std::unordered_set<std::size_t> &memo) {
	if(id >= components.size())
		return rem == 0;
	if(rem == 0) {
		while(id < components.size()) {
			B.push_back(id++);
		}
		return true;
	}
	if(memo.find(c*id + rem) != memo.end())
			return false;
	memo.insert(c*id + rem);
	std::size_t size = components[id].size();
	if(size <= rem) {
		A.push_back(id);
		if(dp_helper(id + 1, rem - size, memo)) return true;
		A.pop_back();
	}
	B.push_back(id);
	if(dp_helper(id + 1, rem, memo)) return true;
	B.pop_back();
	return false;
}

bool dp() {
	std::unordered_set<std::size_t> memo;
	return dp_helper(0, (c - path.size()) / 2, memo);
}

int main() {
	rng.seed(424242);
	std::size_t t;
	std::cin >> c >> t;
	pool.reserve(c);
	visited.reserve(c);
	A.reserve(c / 2);
	B.reserve(c / 2);
	components.reserve(c);

	graph.resize(c);
	while(t--) {
		std::size_t a,b;
		std::cin >> a >> b;
		--a; --b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	bool is_ok = false;
	do {
		path.clear();
		visited.assign(c, false);
		components.clear();
		create_path();
		if((c - path.size()) % 2 != 0) {
			visited[path.back()] = false;
			path.pop_back();
		}
		calc_components();
		is_ok = dp();
	} while(!is_ok);

	std::cout << path.size() << ' ' << (c - path.size()) / 2 << std::endl;
	for(std::size_t elem : path) std::cout << elem + 1 << ' ';
	std::cout << std::endl;
	for(std::size_t id : A) for(std::size_t elem : components[id]) std::cout << elem + 1 << ' ';
	std::cout << std::endl;
	for(std::size_t id : B) for(std::size_t elem : components[id]) std::cout << elem + 1 << ' ';
	std::cout << std::endl;
	return 0;
}
