#include <stdio.h>
#define rep(E, F) for (E = 0; E < (F); E++)
typedef long long ll;
int get_int();
#define MAX 10000
#define INF (1LL << 60)
ll min(ll a, ll b) { return a < b ? a : b; }

ll d[MAX];
ll foo(ll x, ll* a, ll n)
{
	if (x >= MAX)
	{
		ll mx = 0, i;
		rep(i, n) if (a[i]*(mx + 1) < a[mx]*(i + 1)) mx = i;
		ll k = (x - MAX + 1 + mx)/(mx + 1);
		return foo(x - k*(mx + 1), a, n) + k*a[mx];
	}
	if (x == 0) return 0;
	if (x <= n) return a[x - 1];
	if (d[x] != -1) return d[x];
	ll i;
	d[x] = INF;
	rep(i, n) d[x] = min(d[x], a[i] + foo(x - i - 1, a, n));
	return d[x];
}

int main()
{
	ll n = get_int(), q = get_int();
	ll i, a[n];
	rep(i, MAX) d[i] = -1;
	rep(i, n) a[i] = get_int();
	rep(i, q) printf("%lld\n", foo(get_int(), a, n));
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
