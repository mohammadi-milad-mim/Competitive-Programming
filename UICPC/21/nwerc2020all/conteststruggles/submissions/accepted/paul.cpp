#include <cstdio>

int main() {
	int n, k;
	double a, s;
	scanf("%d%d%lf%lf", &n, &k, &a, &s);

	double res = (n*a-k*s)/(n-k);
	if (res < -1e-9 || res > 100+1e-9) printf("impossible\n");
	else printf("%.10f\n", (n*a-k*s)/(n-k));
}
