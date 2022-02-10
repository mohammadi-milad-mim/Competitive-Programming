#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#define rep(E, F) for (E = 0; E < (F); E++)
typedef long long ll;
ll get_int();

ll foo(ll x, ll y, ll a, ll b)
{
	return (x - a)*(x - a) + (y - b)*(y - b);
}

int main()
{
	srand(time(NULL));
	ll x = 0, y = 0, n = get_int();
	while (n > 0)
	{
		x = rand()%1000001, y = rand()%1000001;
		while (1)
		{
			if (x < 1) x = 1;
			if (y < 1) y = 1;
			if (x >= 1000000) x = 999999;
			if (y >= 1000000) y = 999999;
			printf("%lld %lld\n", x, y); fflush(stdout); ll g = get_int(), gg;
			if (g == 0) break;
			if (g == 1)
			{
				printf("%lld %lld\n", x + 1, y); fflush(stdout); g = get_int();
				if (g == 0) { x++; break; }
				printf("%lld %lld\n", x - 1, y); fflush(stdout); g = get_int();
				if (g == 0) { x--; break; }
				printf("%lld %lld\n", x, y - 1); fflush(stdout); g = get_int();
				if (g == 0) { y--; break; }
				printf("%lld %lld\n", x, y + 1); fflush(stdout); g = get_int();
				if (g == 0) { y++; break; }
				assert(0);
			}
			if (g == 2)
			{
				printf("%lld %lld\n", x + 1, y + 1); fflush(stdout); g = get_int();
				if (g == 0) { x++, y++; break; }
				printf("%lld %lld\n", x + 1, y - 1); fflush(stdout); g = get_int();
				if (g == 0) { x++, y--; break; }
				printf("%lld %lld\n", x - 1, y - 1); fflush(stdout); g = get_int();
				if (g == 0) { x--, y--; break; }
				printf("%lld %lld\n", x - 1, y + 1); fflush(stdout); g = get_int();
				if (g == 0) { x--, y++; break; }
				assert(0);
			}
			printf("%lld %lld\n", x + 1, y); fflush(stdout); gg = get_int();
			ll dx = gg - g;
			printf("%lld %lld\n", x, y + 1); fflush(stdout); gg = get_int();
			ll dy = gg - g;
			if (dx == 0 && dy == 0) x = rand()%1000001, y = rand()%1000001;
			else x -= (dx + 1)/2, y -= (dy + 1)/2;
		}
		n--;
	}
	return 0;
}

ll get_int()
{
	ll ret = 0;
	char c = getchar();
	ll sgn;

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
