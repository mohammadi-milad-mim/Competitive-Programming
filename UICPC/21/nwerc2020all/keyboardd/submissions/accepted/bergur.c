#include <stdio.h>
#define rep(E, F) for (E = 0; E < (F); E++)
int get_string(char*, char);

int rle(char* s, char* a, int* b)
{
	int k = 0;
	while (*s != '\0')
	{
		char* t = s;
		b[k] = 0, a[k] = *s;
		while (*s == *t) t++, b[k]++;
		k++;
		s = t;
	}
	return k;
}

int main()
{
	char s[1001], t[1001], a[1001], b[1001], o[256];
	int aa[1001], bb[1001], i;
	get_string(s, 10);
	get_string(t, 10);
	int n = rle(s, a, aa);
	int m = rle(t, b, bb);
	rep(i, 256) o[i] = 0;
	rep(i, n) if (aa[i] != bb[i]) o[a[i]] = 1;
	rep(i, 256) if (o[i]) printf("%c", i); printf("\n");
	return 0;
}

int get_string(char* b, char t)
{
	int i = 0;
	b[i++] = getchar();
	while (b[i - 1] != t) b[i++] = getchar();
	b[i - 1] = '\0';
	return i - 1;
}
