#include <cstdio>

int main() {
	int n, k, a, s;
	scanf("%d%d%d%d", &n, &k, &a, &s);

	double res = double(n*a-k*s)/(n-k);
	if (res < 0 || res > 100) printf("impossible\n");
	else printf("%.10f\n", res);
}
