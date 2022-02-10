/**
* Generates multiple layers of circles (similar to concentric circles)
* with connections between consecutive circles (optinally last one can connect to first one, too)
*/

#include <algorithm>
#include <vector>
#include <set>

#include "icpc_gen_helper.h"

using namespace icpc_gen_helper;


void add_circle(std::vector<std::pair<std::size_t, std::size_t>> &tunnels, std::size_t from, std::size_t to) {
	for(std::size_t i = from; i < to; ++i) {
		tunnels.push_back({i, i + 1});
	}
	tunnels.push_back({from, to});
}

int main(int argc, char** argv) {
	Init(argc, argv);
	unsigned long long n = std::stoull(getParam("--max_n"));
	unsigned long long max_k = std::stoull(getParam("--max_k"));
	unsigned long long layers = std::stoull(getParam("--max_layer"));
	unsigned long long max_conn = std::stoull(getParam("--max_conn"));
	bool wrap_around = hasFlag("--torus");

	assert(layers > 1);
	assert(max_conn >= 2);
	
	unsigned long long k = 0;

	std::vector<std::pair<std::size_t, std::size_t>> tunnels;
	unsigned long long cur_n = 0, n_layer = n / layers;
	unsigned long long n_layer_h = n_layer + n_layer / 10;
	unsigned long long n_layer_l = n_layer - (2*n_layer) / 10;
	unsigned long long next_layer = uniform_number(n_layer_l, n_layer_h), last_layer = 0, first_layer = next_layer;
	std::cerr << "Range : " << n_layer_l << " - " << n_layer_h << std::endl;
	k = 0;

	while(layers > 0 && cur_n + next_layer <= n && k + next_layer + 2 <= max_k) {
		add_circle(tunnels, cur_n + 1, cur_n + next_layer);
		k += next_layer;
		if(last_layer != 0) {
			unsigned long long conn_h = std::min(max_k - k, max_conn);
			unsigned long long conns = uniform_number(2ULL, conn_h);
			std::set<std::pair<unsigned long long, unsigned long long>> new_conns;
			while(conns) {
				unsigned long long from = uniform_number(cur_n - last_layer + 1, cur_n);
				unsigned long long to = uniform_number(cur_n + 1, cur_n + next_layer);
				if(new_conns.count({from, to}) == 0) {
					new_conns.insert({from, to});
					tunnels.push_back({from, to});
					++k;
					--conns;
				}
			}
		}
		last_layer = next_layer;
		cur_n += next_layer;
		next_layer = uniform_number(n_layer_l, n_layer_h);
		--layers;
	}
	if(wrap_around) {
		assert(k + 2 <= max_k);
		unsigned long long conn_h = std::min(max_k - k, max_conn);
		unsigned long long conns = uniform_number(2ULL, conn_h);
		std::set<std::pair<unsigned long long, unsigned long long>> new_conns;
		while(conns) {
			unsigned long long from = uniform_number(cur_n - last_layer + 1, cur_n);
			unsigned long long to = uniform_number(1ULL, first_layer);
			if(new_conns.count({from, to}) == 0) {
				new_conns.insert({from, to});
				tunnels.push_back({from, to});
				++k;
				--conns;
			}
		}
	}

	
	std::cerr << "Layers: " << layers << " from " << getParam("--max_layer") << std::endl;
	std::cerr << cur_n << " " << k << std::endl;

	std::cout << cur_n << " " << k << std::endl;
	Random_Mapping mp(1ULL,cur_n);
	do_shuffle(tunnels);
	for(auto &p : tunnels) {
		if(uniform_number(0,1) == 0)
			std::swap(p.first, p.second);
		std::cout << mp[p.first] << " " << mp[p.second] << std::endl;
	}
	return 0;
}
