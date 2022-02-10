#include<cstdio>
#include<iostream>
using namespace std;
int main() {
	int n, k, d, s;
	cin >> n >> k >> d >> s;
	int det = n*d - k*s;
	if (0 <= det && det <= (n-k) * 100) {
		printf("%.9lf\n", 1.0 * det / (n-k));
	} else
		printf("impossible\n");
	return 0;
}
