#include <bits/stdc++.h>
using namespace std;
class NumMatrix 
{
   public:
   vector < vector <long long int>> dp;
   NumMatrix(vector<vector<long long int>>& matrix) 
   {
      int n = matrix.size();
      if(!n) return;
      int m = matrix[0].size();
      dp = vector<vector<long long int>>(n, vector <long long int> (m));
      for(int i = 0; i < n; i++){
         for(int j = 0 ;j < m; j++){
            dp[i][j] = j - 1 < 0 ? matrix[i][j] : dp[i][j - 1] + matrix[i][j];
         }
      }
      for(int i = 1; i < n; i++){
         for(int j = 0; j < m; j++){
            dp[i][j] += dp[i - 1][j];
         }
      }
   }
   long long int sumRegion(int row1, int col1, int row2, int col2) 
   {
      long long int ret = dp[row2][col2];
      long long int sub1 = row1 - 1 < 0 ? 0 : dp[row1 - 1][col2];
      long long int sub2 = col1 - 1 < 0 ? 0 : dp[row2][col1 - 1];
      long long int add = row1 - 1 < 0 || col1 - 1 < 0 ? 0 : dp[row1 - 1][col1 - 1];
      return ret - sub1 - sub2 + add;
   }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int I,J; cin>>I>>J;
   vector<vector<long long int>> mat(I);
   int t;
   for (int i = 0; i < I; i++)
    {
        for (int j = 0; j < J; j++)
        {
            cin>>t;
            mat[i].push_back(t);
        }
    }
   NumMatrix ob(mat);
   int T; cin>>T;
   int tli,tlj,rbi,rbj;
   while (T--)
   {
       cin>>tli>>rbi>>tlj>>rbj;
       cout << ob.sumRegion(tli,tlj,rbi,rbj) << "\n";
   }
}