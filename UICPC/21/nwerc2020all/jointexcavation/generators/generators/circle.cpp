/**
* Generates a simple circle
*/

#include <algorithm>
#include <vector>
#include <unordered_set>

#include "icpc_gen_helper.h"

using namespace icpc_gen_helper;


int main(int argc, char** argv) {
	Init(argc, argv);
	unsigned long long n = std::stoull(getParam("--max_n"));

	Random_Mapping mp(1,n);
	std::cout << n << " " << n << std::endl;
	for(unsigned long long i = 1; i < n; ++i) {
		std::cout << mp[i]<< " " << mp[i + 1] << std::endl;
	}
	std::cout << mp[n] << " " << mp[1] << std::endl;
	return 0;
}
