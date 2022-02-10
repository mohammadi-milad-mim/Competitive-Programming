/**
 * Generates a network of multiple islands.
 * Islands are connected to each other via one bridge.
 * Islands consist of multiple nodes that form a circle with additional edges inbetween.
 * Multiple islands cannot be visited in a roundtrip
 * (i.e. if island A is connected to B and B connected to C, then A is never connected to C)
 */

#include <algorithm>
#include <cstdio>
#include <memory>
#include <unordered_set>
#include <unordered_map>
#include <vector>

#include "icpc_gen_helper.h"

using namespace icpc_gen_helper;


int main(int argc, char** argv) {
	Init(argc, argv);
	unsigned long long n = std::stoull(getParam("--max_n"));
	unsigned long long k = std::stoull(getParam("--max_k")), k_now = k;
	unsigned long long max_size = std::stoull(getParam("--max_size"));

	std::vector<std::pair<std::size_t, std::size_t>> islands;
	islands.reserve(n);

	std::vector<std::pair<std::size_t, std::size_t>> edges;
	edges.reserve(k);
	{
		std::vector<std::pair<std::size_t, std::size_t>> pot_edges;

		for(unsigned long long n_now = n; n_now > 0;) {
			unsigned long long this_size = std::min(uniform_number(1ULL, max_size), n_now);
			n_now -= this_size;
			std::size_t off = n_now + 1;

			if(this_size > 1) {
				for(std::size_t i = this_size - 1; i > 0;) {
					--i;
					edges.push_back({off + i, off + i + 1});
					for(std::size_t j = i + 2; j < this_size; ++j) {
						pot_edges.push_back({off + i, off + j});
					}
				}
				// last potential edge is 0--max_index
				edges.push_back(pot_edges.back());
				pot_edges.pop_back();
				k_now -= this_size;
			}
			if(islands.size() > 0) {
				auto rnd_is = islands[uniform_number(0UL, islands.size() - 1)];
				edges.push_back({rnd_is.first + uniform_number(0UL, rnd_is.second - 1), off + uniform_number(0ULL, this_size - 1)});
				--k_now;
			}
			islands.push_back({off, this_size});
		}
		k = k - k_now + std::min((std::size_t) k_now, pot_edges.size());
		k_now = std::min((std::size_t) k_now, pot_edges.size());

		Random_Selection sel(pot_edges, k_now);

		for(auto it : sel) {
			edges.push_back(*it);
		}
	}

	do_shuffle(edges);
	Random_Mapping mp(1,n);

	std::cout << n << ' ' << k << std::endl;
	for(auto &p : edges) {
		if(uniform_number(0,1) == 0)
			std::swap(p.first, p.second);
		std::cout << mp[p.first] << ' ' << mp[p.second] << std::endl;
	}

	return 0;
}
