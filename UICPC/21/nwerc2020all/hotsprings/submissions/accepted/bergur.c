#include <stdio.h>
#include <stdlib.h>
#define rep(E, F) for (E = 0; E < (F); E++)
int get_int();
int cmp(const void* p1, const void* p2) { return *(int*)p1 - *(int*)p2; }

int main()
{
	int n = get_int();
	int i, a[n];
	rep(i, n) a[i] = get_int();
	qsort(a, n, sizeof(a[0]), cmp);
	if (n%2 == 1)
	{
		printf("%d ", a[n/2]);
		rep(i, n/2) printf("%d %d ", a[n/2 - 1 - i], a[n/2 + 1 + i]);
		printf("\n");
	}
	else
	{
		rep(i, n/2) printf("%d %d ", a[n/2 - i - 1], a[n/2 + i]);
		printf("\n");
	}
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
