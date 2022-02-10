#include <cstdio>
#include <vector>

#define MAXN 500

using namespace std;

int dst[MAXN];
int start[3][MAXN][MAXN];
int endt[3][MAXN][MAXN];
int p[3][MAXN];
bool can[3][3][MAXN][MAXN];

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

  // This looks terrible, but it is in O(n^3)
  // For each pair of persons we compute where
  // they could start without overlapping times.
  for(int p1 = 0; p1 < 3; p1++) {
    for(int p2 = p1 + 1; p2 < 3; p2++) {
      for(int s1 = 0; s1 < n; s1++) {
	for(int s2 = 0; s2 < n; s2++) {
	  can[p1][p2][s1][s2] = true;
	  for(int i = 0; i < n; i++) {
	    if(endt[p1][s1][i] > start[p2][s2][i] && endt[p2][s2][i] > start[p1][s1][i]) {
	      can[p1][p2][s1][s2] = false;
	    }
	  }
	}
      }
    }
  }
  
  // Now bruteforce starting locations in O(n^3)
  for(int s1 = 0; s1 < n; s1++) {
    for(int s2 = 0; s2 < n; s2++) {
      for(int s3 = 0; s3 < n; s3++) {
	if(can[0][1][s1][s2] && can[0][2][s1][s3] && can[1][2][s2][s3]) {
	  printf("%d %d %d\n", s1+1, s2+1, s3+1);
	  return 0;
	}
      }
    }
  }
  
  printf("impossible\n");
  return 0;
}

