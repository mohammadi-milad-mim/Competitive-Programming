#include <stdio.h>
#define rep(E, F) for (E = 0; E < (F); E++)
int get_int();
typedef long long ll;

ll foo(ll x, ll* a, ll y, ll* b, ll* c, ll n)
{
	ll t[2][n][2], i, z, w;
	rep(i, n) t[0][i][0] = t[1][i][0] = -1;
	z = x, w = 0;
	while (t[0][z][0] == -1)
	{
		t[0][z][0] = w, t[0][z][1] = w + a[z];
		w += a[z] + c[z], z++;
		if (z == n) z = 0;
	}
	z = y, w = 0;
	while (t[1][z][0] == -1)
	{
		t[1][z][0] = w, t[1][z][1] = w + b[z];
		w += b[z] + c[z], z++;
		if (z == n) z = 0;
	}
	rep(i, n) if (
			t[0][i][0] >= t[1][i][0] && t[0][i][0] < t[1][i][1] ||
			t[1][i][0] >= t[0][i][0] && t[1][i][0] < t[0][i][1]) return 0;
	return 1;
}

int main()
{
	ll n = get_int();
	ll i, j, k, a[n], b[3][n], d[3][n][n];
	rep(i, n) a[i] = get_int();
	rep(i, 3) rep(j, n) rep(k, n) d[i][j][k] = 0;
	rep(j, 3) rep(i, n) b[j][i] = get_int();
	rep(i, n) rep(j, n) d[0][i][j] = foo(i, b[0], j, b[1], a, n);
	rep(i, n) rep(j, n) d[1][i][j] = foo(i, b[1], j, b[2], a, n);
	rep(i, n) rep(j, n) d[2][i][j] = foo(i, b[2], j, b[0], a, n);
	rep(i, n) rep(j, n) if (d[0][i][j]) rep(k, n) if (d[1][j][k] && d[2][k][i])
	{
		printf("%d %d %d\n", i + 1, j + 1, k + 1);
		return 0;
	}
	printf("impossible\n");
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
