/**
 * This submission assigns the nodes first and then tries
 * to find a path over the unassigned nodes.
 *
 * Goes wrong since it tries to maximise the number of assigned nodes
 * but this does rarely lead to a possible path on higher node numbers.
 */

#include <deque>
#include <iostream>
#include <random>
#include <vector>

#define PATH_ATTEMPTS 10

std::vector<std::vector<std::size_t>> graph;
std::vector<std::size_t> pool, unassigned;
// colors: 0 - unassigned, 1 - path, 2 - A, 3 - B
std::vector<char> color;
std::deque<std::size_t> path;
std::size_t c;
std::mt19937 rng;

inline std::size_t draw(std::vector<std::size_t> &vec) {
	std::size_t len = vec.size(), sel = rng() % len, elem = vec[sel];
	std::swap(vec[sel], vec[len - 1]);
	vec.pop_back();
	return elem;
}


// Check for path; we are searching for a Hamilton path...
bool check() {
	std::size_t attempts = PATH_ATTEMPTS;
	path.clear();
	do {
		std::size_t start = unassigned[rng() % unassigned.size()];
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
				color[next] = 1;
				cur = next;
				next = c;
				pool.clear();
				for(std::size_t neigh : graph[cur]) {
					if(!color[neigh])
						pool.push_back(neigh);
				}
				if(pool.size()) {
					next = pool[rng() % pool.size()];
				}
			} while(next != c);
			forward = !forward;
		} while(!forward);

		if(path.size() == unassigned.size())
			return true;
		path.clear();
		for(std::size_t elem : unassigned) {
			color[elem] = 0;
		}
	} while(--attempts);
	return false;
}

int main() {
	rng.seed(424242);
	long long t;
	std::cin >> c >> t;
	graph.resize(c);
	pool.reserve(c);
	unassigned.reserve(c);
	while(t--) {
		long long a,b;
		std::cin >> a >> b;
		--a; --b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	std::vector<std::size_t> A, B;
	A.reserve(c / 2); B.reserve(c / 2);

	bool is_ok = false;
	while(!is_ok) {
		unassigned.clear();
		A.clear();
		B.clear();
		pool.resize(c);
		for(std::size_t i = 0; i < c; ++i) pool[i] = i;
		path.assign(c, c);
		color.assign(c, 0);
		// Randomly assign nodes to A or B
		while(pool.size() > 0) {
			std::size_t elem = draw(pool);
			char forced_color = 0;
			// check dependencies
			for(std::size_t neigh : graph[elem]) {
				if(color[neigh] != forced_color && color[neigh] != 0) {
					if(forced_color == 0) forced_color = color[neigh];
					else {
						forced_color = 1;
						break;
					}
				}
			}

			if(forced_color == 1) {
				unassigned.push_back(elem);
			} else {
				// If no dependency, put into group with less elements (or A if equal)
				if(forced_color == 0) forced_color = 2 + (A.size() > B.size());
				color[elem] = forced_color;
				if(forced_color == 2) {
					A.push_back(elem);
				} else {
					B.push_back(elem);
				}
			}
		}
		if(B.size() > A.size())
			std::swap(A, B);
		// Even out groups
		while(A.size() > B.size()) {
			std::size_t elem = A.back();
			unassigned.push_back(elem);
			color[elem] = 0;
			A.pop_back();
		}

		// Test to find path
		is_ok = check();
	}

	std::cout << path.size() << ' ' << A.size() << std::endl;
	for(std::size_t i = 0; i < path.size(); ++i) {
		std::cout << path[i] + 1 << ' ';
	}
	std::cout << std::endl;
	for(std::size_t i = 0; i < A.size(); ++i) {
		std::cout << A[i] + 1 << ' ';
	}
	std::cout << std::endl;
	for(std::size_t i = 0; i < B.size(); ++i) {
		std::cout << B[i] +  1<< ' ';
	}
	std::cout << std::endl;


	return 0;
}
