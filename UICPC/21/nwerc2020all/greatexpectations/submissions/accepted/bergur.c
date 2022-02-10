#include <stdio.h>
#include <math.h>
#define rep(E, F) for (E = 0; E < (F); E++)
int get_int();
double get_double();

double p[51], d[51][5001];
int a[51], b[51];
double foo(int x, int y, double t, int m, int r)
{
	double k = a[x] - (x == 0 < 0 ? 0 : a[x - 1]);
	if (x == m) return k + y < r ? k : t;
	if (y >= r) return t;
	if (d[x][y] > -1.0) return d[x][y];
	return d[x][y] =
		p[x]*(foo(x + 1, y + k, t, m, r) + k) +
		 (1.0 - p[x])*(
			 fmin(foo(x + 1, y + k + b[x], t, m, r) + k + b[x], t + k)
			 );
}

int main()
{
	int i, j, n = get_int(), r = get_int(), m = get_int();
	rep(i, m) a[i] = get_int(), p[i] = get_double(), b[i] = get_int();
	a[m] = n;
	double l = 0.0, s = 1e12;
	while (s - l > 1e-7)
	{
		double t = (l + s)/2.0, e;
		rep(i, m) rep(j, r) d[i][j] = -10.0;
		e = foo(0, 0, t, m, r);
		if (e > t) l = t;
		else s = t;
	}
	printf("%.8f\n", foo(0, 0, l, m, r));
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

double get_double()
{
	double ret = 0;
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
		if (c == '.')
		{
			double pos = 0.1;
			c = getchar();
			while (c >= '0' && c <= '9')
			{
				ret += pos*(c - '0');
				pos /= 10;
				c = getchar();
			}
			return sgn*ret;
		}
		else if (c < '0' || c > '9') return sgn*ret;
	}
}
