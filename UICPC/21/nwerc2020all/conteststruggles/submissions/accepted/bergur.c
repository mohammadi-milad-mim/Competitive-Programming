#include <stdio.h>
#define rep(E, F) for (E = 0; E < (F); E++)
int get_int();

int main()
{
	double n = get_int(), k = get_int(), d = get_int(), s = get_int();
	if ((d*n - s*k)/(n - k) > -1e-9 && (d*n - s*k)/(n - k) < 100 + 1e-9) printf("%.8f\n", (d*n - s*k)/(n - k));
	else printf("impossible\n");
	return 0;
}

int get_int()
{
	int ret = 0;
	char c = getchar();
	int sgn;

	while (1)
	{
		if (c == EOF) return EOF;
		if (c >= '0' && c <= '9') { sgn = 1; break; }
		if (c == '-')
		{
			c = getchar();
			if (c < '0' || c > '9') continue;
			sgn = -1;
			break;
		}
		c = getchar();
	}

	while (1)
	{
		ret = ret*10 + c - '0';
		c = getchar();
		if (c < '0' || c > '9') return sgn*ret;
	}
}
