#include <cstdio>
#include <vector>

#define MAXN 500

using namespace std;

int dst[MAXN];
int start[3][MAXN][MAXN];
int endt[3][MAXN][MAXN];
int p[3][MAXN];

int main() {
  int n;
  scanf("%d\n", &n);

  for(int i = 0; i < n; i++)
    scanf("%d", &dst[i]);

  for(int i = 0; i < 3; i++)
    for(int j = 0; j < n; j++)
      scanf("%d", &p[i][j]);

  // Precompute start and end times for k when person i starts at position j
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < n; j++) {
      int s = 0;
      for(int k = 0; k < n; k++) {
	start[i][j][(j+k)%n] = s;
	s += p[i][(j+k)%n];
	endt[i][j][(j+k)%n] = s;
	s += dst[(j+k)%n];
      }
    }
  }
  
  // Now bruteforce starting locations in O(n^4)
  for(int s1 = 0; s1 < n; s1++) {
    for(int s2 = 0; s2 < n; s2++) {
      for(int s3 = 0; s3 < n; s3++) {
	bool can = true;
	vector<int> s = { s1, s2, s3 };
	for(int i = 0; can && i < n; i++) {
	  if(endt[0][s[0]][i] > start[1][s[1]][i] && endt[1][s[1]][i] > start[0][s[0]][i])
	    can = false;
	  if(endt[1][s[1]][i] > start[2][s[2]][i] && endt[2][s[2]][i] > start[1][s[1]][i])
	    can = false;
	  if(endt[2][s[2]][i] > start[0][s[0]][i] && endt[0][s[0]][i] > start[2][s[2]][i])
	    can = false;
	}

	if(can) {
	  printf("%d %d %d\n", s1+1, s2+1, s3+1);
	  return 0;
	}
      }
    }
  }
  
  printf("impossible\n");
  return 0;
}
