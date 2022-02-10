#include <assert.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#define rep(E, F) for (E = 0; E < (F); E++)
#define per(E, F) for (E = (F) - 1; E >= 0; E--)
int get_int();

int* g[200001], gg[200001], gp[2*200001], f[200001];
int a = 0, b, s[200001], ss = 0;
void foo(int x, int n)
{
	int i;
	b--, f[x] = 0, s[ss++] = x;
	if (a == b)
	{
		printf("%d %d\n", ss, a);
		rep(i, ss) printf("%d ", s[i] + 1); printf("\n");
		rep(i, n) if (f[i] == 1) printf("%d ", i + 1); printf("\n");
		rep(i, n) if (f[i] == 2) printf("%d ", i + 1); printf("\n");
		exit(0);
	}
	rep(i, gg[x]) if (f[g[x][i]] == 1) foo(g[x][i], n);
	ss--, f[x] = 2, a++;
	if (a == b)
	{
		printf("%d %d\n", ss, a);
		rep(i, ss) printf("%d ", s[i] + 1); printf("\n");
		rep(i, n) if (f[i] == 1) printf("%d ", i + 1); printf("\n");
		rep(i, n) if (f[i] == 2) printf("%d ", i + 1); printf("\n");
		exit(0);
	}
}

int main()
{
	int i, j, n = get_int(), m = get_int();
	int x[m], y[m], d[n + 1];
	b = n;
	rep(i, n + 1) d[i] = 0;
	rep(i, n) gg[i] = 0;
	rep(i, n) f[i] = 1;
	rep(i, m) x[i] = get_int() - 1, y[i] = get_int() - 1;
	rep(i, m) d[x[i] + 1]++, d[y[i] + 1]++;
	rep(i, n) if (i != 0) d[i] += d[i - 1];
	rep(i, m)
	{
		gp[d[x[i]] + gg[x[i]]++] = y[i];
		gp[d[y[i]] + gg[y[i]]++] = x[i];
	}
	rep(i, n) g[i] = &gp[d[i]];
	foo(0, n);
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
