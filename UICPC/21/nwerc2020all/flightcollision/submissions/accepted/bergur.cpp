#include <bits/stdc++.h>
using namespace std;
#define rep(E, F) for (E = 0; E < (F); E++)
int get_int();
typedef pair<int, int> ii;
typedef pair<long double, ii> iii;

long double foo(int a, int b, int x, int y)
{
	if (b == y) return -1.0;
	return (long double)(x - a)/(b - y);
}

int main()
{
	int i, n = get_int();
	int a[n], b[n], c[n];
	long double g;
	rep(i, n) a[i] = get_int(), b[i] = get_int(), c[i] = 1;
	set<int> s;
	set<iii> t;
	map<ii, long double> m;
	rep(i, n + 2) s.insert(i - 1);
	rep(i, n - 1)
	{
		long double x = foo(a[i], b[i], a[i + 1], b[i + 1]);
		if (x > 0.0) t.insert(iii(x, ii(i, i + 1))), m[ii(i, i + 1)] = x;
	}
	while (t.size() > 0)
	{
		iii p = *t.begin();
		int x = p.second.first, y = p.second.second;
		s.erase(x), s.erase(y);
		auto it = s.lower_bound(x);
		int w = *it, z = *(--it);
		t.erase(t.begin());
		if (z > -1 && m.find(ii(z, x)) != m.end()) t.erase(iii(m[ii(z, x)], ii(z, x)));
		if (w < n && m.find(ii(y, w)) != m.end()) t.erase(iii(m[ii(y, w)], ii(y, w)));
		if (z > -1 && w < n && 0.0 < (g = foo(a[z], b[z], a[w], b[w]))) t.insert(iii(g, ii(z, w))), m[ii(z, w)] = g;
	}
	printf("%d\n", s.size() - 2);
	while (s.size() > 0)
	{
		if (*s.begin() > -1 && *s.begin() < n) printf("%d ", 1 + *s.begin());
		s.erase(s.begin());
	}
	printf("\n");
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
