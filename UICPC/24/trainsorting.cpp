#include <bits/stdc++.h>
using namespace std;
int LIS[2001], LDS[2001];
vector<int> nums;

int lds_fu(int lds[], int i, int n)
{
  if (lds[i] != -1)
  {
      return lds[i];
  }
  int ma= 0;
  for(int j = i; j < n; ++j)
    if (nums[j] > nums[i])
    {
        ma = max(ma, lds_fu(j));
    }
    lds[i]=ma+1;
    

  return lds[i];
}

int lis_fu(int lis[], int i, int n)
{
  if (LIS[i] != -1)
  {
      return LIS[i];
  }

  int ma = 0;
  for(int j = i; j < n; ++j)
    if (nums[j] < nums[i])
    {
        ma= max(ma, lis_fu(j));
    }
    LIS[i]=ma+1;
  return LIS[i];
}

int main()
{
    int n; cin>>n;
    int lis[n], lds[n];
    int t;
    for (int i = 0; i < n; i++)
    {
        cin>>t;
        nums.push_back(t);
    }

    
}