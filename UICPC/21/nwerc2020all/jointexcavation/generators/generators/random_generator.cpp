/**
* Generates a random graph by first creating a random
* spanning tree via Random Walk and then adding edges until
* max edges are reached
*/

#include <algorithm>
#include <vector>
#include <unordered_set>

#include "icpc_gen_helper.h"

using namespace icpc_gen_helper;


int main(int argc, char** argv) {
	Init(argc, argv);
	unsigned long long n = std::stoull(getParam("--max_n"));
	unsigned long long k = std::stoull(getParam("--max_k"));

	k = std::min(std::max(n - 1, k), (n * (n - 1)) / 2);
	std::vector<bool> vis((std::size_t) n, false);
	Random_Generation sel(0ULL, n * n);
	// Random Walk to create minimal spanning tree
	unsigned long long not_vis = n - 1;
	std::size_t cur = 0;
	vis[0] = true;
	while(not_vis > 0) {
		std::size_t next = uniform_number(0ULL, n - 1);
		if(!vis[next]) {
			sel.Select(cur*n + next);
			vis[next] = true;
			--not_vis;
		}
		cur = next;
	}
	sel.Generate(0ULL, n * n, 2*k - n + 2);
	Random_Mapping mp(n);
	std::vector<std::unordered_set<std::size_t>> graph((std::size_t) n);
	std::cout << n << " " << k << std::endl;
	for(auto s : sel) {
		unsigned long long a = s / n, b = s % n;
		if(a != b && graph[a].count(b) == 0) {
			graph[a].insert(b);
			graph[b].insert(a);
			std::cout << mp[a] + 1 << " " << mp[b] + 1 << std::endl;
			--k;
			if(!k)
				return 0;
		}
	}
	return 1;
}
