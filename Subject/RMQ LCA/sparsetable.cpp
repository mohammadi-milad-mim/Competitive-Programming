#include <bits/stdc++.h>
using namespace std;
#define MAX 500

int lookup[MAX][MAX];
 
void buildSparseTable(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        lookup[i][0] = arr[i];
    for (int j = 1; (1 << j) <= n; j++) {

        for (int i = 0; (i + (1 << j) - 1) < n; i++) {
 
            lookup[i][j] = lookup[i][j - 1]^lookup[i + (1 << (j - 1))][j - 1];
        }
    }
}
 
// Returns minimum of arr[L..R]
int query(int L, int R)
{
    // Find highest power of 2 that is smaller
    // than or equal to count of elements in given
    // range. For [2, 10], j = 3
    int j = (int)log2(R - L + 1);
 
    // Compute minimum of last 2^j elements with first
    // 2^j elements in range.
    // For [2, 10], we compare arr[lookup[0][3]] and
    // arr[lookup[3][3]],
    if (lookup[L][j] <= lookup[R - (1 << j) + 1][j])
        return lookup[L][j];
 
    else
        return lookup[R - (1 << j) + 1][j];
}
 
// Driver program
int main()
{
    int a[] = { 7, 2, 3, 0, 5, 10, 3, 12, 18 };
    int n = sizeof(a) / sizeof(a[0]);
    buildSparseTable(a, n);
    cout << query(0, 4) << endl;
    cout << query(4, 7) << endl;
    cout << query(7, 8) << endl;
    return 0;
}