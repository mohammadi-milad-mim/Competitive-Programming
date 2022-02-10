#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define rep(E, F) for (E = 0; E < (F); E++)
int get_int();
typedef struct { int x, y; } par;

int cmp(const void* p1, const void* p2)
{
	if (((par*)p1)->x == ((par*)p2)->x) return ((par*)p1)->y - ((par*)p2)->y;
	return ((par*)p1)->x - ((par*)p2)->x;
}

int isin(int x, int y, int n)
{
	if (x < 0 || y < 0) return 0;
	if (x >= n || y >= n) return 0;
	return 1;
}

int foo(par* a, int ax, int ay, int bx, int by, int n)
{
	int k1 = 0, k2 = 0, i, j;
	rep(i, n) if (ax + a[i].x == bx && ay + a[i].y == by) return 1;
	par b[n], c[n];
	rep(i, n) if (isin(ax + a[i].x, ay + a[i].y, n)) b[k1].x = ax + a[i].x, b[k1].y = ay + a[i].y, k1++;
	rep(i, n) if (isin(bx - a[i].x, by - a[i].y, n)) c[k2].x = bx - a[i].x, c[k2].y = by - a[i].y, k2++;
	qsort(b, k1, sizeof(b[0]), cmp);
	qsort(c, k2, sizeof(c[0]), cmp);

	i = j = 0;
	while (i < k1 && j < k2)
	{
		if (b[i].x == c[j].x && b[i].y == c[j].y) return 1;
		else if (b[i].x == c[j].x) b[i].y < c[j].y ? i++ : j++;
		else b[i].x < c[j].x ? i++ : j++;
	}
	return 0;
}

int main()
{
	srand(time(NULL));
	int i, m = 1000, n = get_int(), ax = get_int() - 1, ay = get_int() - 1, bx = get_int() - 1, by = get_int() - 1, x, y;
	par a[n];
	rep(i, n) a[i].x = get_int(), a[i].y = get_int();
	if (foo(a, ax, ay, bx, by, n))
	{
		printf("Alice wins\n");
		return 0;
	}
	rep(i, m)
	{
		x = rand()%n, y = rand()%n;
		if (x != bx && y != by && !foo(a, bx, by, x, y, n)) break;
	}
	if (i == m) printf("Bob wins\n");
	else printf("tie %d %d\n", x + 1, y + 1);

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
