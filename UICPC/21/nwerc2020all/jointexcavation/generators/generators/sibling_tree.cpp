/**
* Creates a graph that looks like a binary tree.
* Additionally each depth layer is connected.
* Looks like this:
*
*    o
*   / \
*  o---o 
* / \ / \
* o-o-o-o
*
*/

#include <algorithm>
#include <vector>
#include <unordered_set>

#include "icpc_gen_helper.h"

using namespace icpc_gen_helper;


int main(int argc, char** argv) {
	Init(argc, argv);
	unsigned long long max_n = std::stoull(getParam("--max_n"));
	unsigned long long max_k = std::stoull(getParam("--max_k"));

	unsigned long long n = 1, k = 0, last_n = 1, last_n_start = 0;

	std::vector<std::unordered_set<std::size_t>> graph(max_n);

	while(true) {
		unsigned long long new_n = last_n * 2, new_k = 2*new_n - 1;
		if(k + new_k > max_k || n + new_n > max_n) break;
		for(std::size_t i = 0; i < last_n; ++i) {
			std::size_t from = last_n_start + i, to = n + 2*i;
			if(uniform_number(0,1) == 0) {
				graph[from].insert(to);
			} else {
				graph[to].insert(from);
			}
			if(uniform_number(0,1) == 0) {
				graph[from].insert(++to);
			} else {
				graph[++to].insert(from);
			}
		}
		for(std::size_t i = n; i < n + new_n - 1; ++i) {
			if(uniform_number(0,1) == 0) {
				graph[i].insert(i + 1);
			} else {
				graph[i + 1].insert(i);
			}
		}
		last_n_start = n;
		last_n = new_n;
		n += new_n;
		k += new_k;
	}

	std::vector<std::pair<std::size_t, std::size_t>> tunnels;
	tunnels.reserve(k);
	for(std::size_t i = 0; i < graph.size(); ++i) {
		for(const std::size_t t : graph[i]) {
			tunnels.push_back({i + 1,t + 1});
		}
	}

	Random_Mapping mp(1, n);
	do_shuffle(tunnels);
	std::cout << n << " " << k << std::endl;
	for(const auto &p : tunnels) {
		std::cout << mp[p.first] << " " << mp[p.second] << std::endl;
	}
	return 0;
}
