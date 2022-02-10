/**
* Generates a fully connected graph
*/

#include <algorithm>
#include <set>

#include "icpc_gen_helper.h"

using namespace icpc_gen_helper;


int main(int argc, char** argv) {
	Init(argc, argv);
	unsigned long long n = std::stoull(getParam("--max_n"));
	unsigned long long k = std::stoull(getParam("--max_k"));

	k = std::min(k, (n * (n - 1)) / 2);
	unsigned long long top_n = n + 1, bottom_n = 0;
	while(bottom_n  + 1 < top_n) {
		unsigned long long mid = (top_n + bottom_n ) / 2;
		if(mid * (mid - 1) / 2 > k) {
			top_n = mid;
		} else {
			bottom_n = mid;
		}
	}
	n = bottom_n;
	k = n * (n - 1) / 2;
	
	Random_Mapping mp(n);
	Random_Generation<unsigned long long> sel(0, n * n, n * n);
	std::set<std::pair<unsigned long long, unsigned long long>> tracking;
	std::cout << n << " " << k << std::endl;
	for(auto &s : sel) {
		unsigned long long a = s/n, b = s % n, c = a, d = b;
		if(a != b) {
			if(a > b) std::swap(c, d);
			if(tracking.count({c, d}) == 0) {
				std::cout << mp[a] + 1 << " " << mp[b] + 1 << std::endl;
				tracking.insert({c, d});
			}
		}
	}
	assert(tracking.size() == k);
	return 0;
}
