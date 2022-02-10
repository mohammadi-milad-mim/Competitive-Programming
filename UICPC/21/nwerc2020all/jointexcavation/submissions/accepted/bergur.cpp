#include <bits/stdc++.h>
using namespace std;
#define rep(E, F) for (E = 0; E < (F); E++)
int get_int();
typedef vector<int> vi;
typedef vector<vi> vvi;

int e = 0, a = 0, b, s[200001], ss = 0;
void foo(vvi& g, int x, int* f)
{
	int i, n = g.size();
	b--;
	f[x] = 0;
	s[ss++] = x;
	if (!e && a == b)
	{
		printf("%d %d\n", ss, a);
		if (ss != 0)
		{
			rep(i, ss) printf("%d ", s[i] + 1);
			printf("\n");
		}
		if (a != 0)
		{
			rep(i, n) if (f[i] == 1) printf("%d ", i + 1);
			printf("\n");
		}
		if (a != 0)
		{
			rep(i, n) if (f[i] == 2) printf("%d ", i + 1);
			printf("\n");
		}
		e = 1;
	}
	rep(i, g[x].size()) if (f[g[x][i]] == 1) foo(g, g[x][i], f);
	ss--;
	f[x] = 2;
	a++;
	if (!e && a == b)
	{
		printf("%d %d\n", ss, a);
		if (ss != 0)
		{
			rep(i, ss) printf("%d ", s[i] + 1);
			printf("\n");
		}
		if (a != 0)
		{
			rep(i, n) if (f[i] == 1) printf("%d ", i + 1);
			printf("\n");
		}
		if (a != 0)
		{
			rep(i, n) if (f[i] == 2) printf("%d ", i + 1);
			printf("\n");
		}
		e = 1;
	}
}

int main()
{
	int i, j, n = get_int(), m = get_int();
	int f[n];
	b = n;
	rep(i, n) f[i] = 1;
	vvi g(n);
	rep(i, m)
	{
		int x = get_int() - 1, y = get_int() - 1;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	foo(g, 0, f);
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
