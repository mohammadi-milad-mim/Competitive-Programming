/**
* Generates a star with 1 node as center and multiple beams, one of length 1, one of length 2, ...
*/

#include <vector>

#include "icpc_gen_helper.h"

using namespace icpc_gen_helper;


int main(int argc, char** argv) {
	Init(argc, argv);
	unsigned long long n = std::stoull(getParam("--max_n"));

	std::vector<std::pair<unsigned long long, unsigned long long>> connections;
	connections.reserve(n - 1);
	unsigned long long cur_beam_tgt = 1, cur_beam = 0, this_node = 1;
	for(unsigned long long m = 2; m <= n; ++m) {
		if(uniform_number(0,1) == 0) {
			connections.push_back({this_node, m});
		} else {
			connections.push_back({m, this_node});
		}
		this_node = m;
		if(++cur_beam == cur_beam_tgt) {
			cur_beam = 0;
			++cur_beam_tgt;
			this_node = 1;
		}
	}

	do_shuffle(connections);
	Random_Mapping mp(1,n);

	std::cout << n << " " << n - 1 << std::endl;
	for(auto &p : connections) {
		std::cout << p.first<< " " << p.second << std::endl;
	}
	return 0;
}
