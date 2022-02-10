#include <iomanip>
#include <iostream>

int main() {
	long long n,k,a,s;
	std::cin >> n >> k >> a >> s;
	a *= 10000*1000;
	s *= 10000*1000;
	long long x = (n *a - k * s)/(n - k);
	if(x < 0 || 100 * 10000 * 1000 < x) {
		std::cout << "impossible" << std::endl;
	} else {
		std::cout << x / (10000 * 1000) << "." << std::setfill('0');
		std::cout << std::setw(7)  << x % (10000 * 1000) << std::endl;
	}
	return 0;
}
