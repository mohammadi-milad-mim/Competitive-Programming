#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin>>n;
    int nums[n];
    int t;
    for (int i = 0; i < n; i++)
    {
        cin>>t;
        nums[i]=t;
    }
    sort(nums,nums+n);
    int mdif = -1;
    int i=0;
    int temp;
    if (n%3==0)
    {
        while ((i+2)<n)
        {
            temp = nums[i+2] - nums[i];
            if (temp>mdif) {mdif=temp;}
            i+=3;
        }
    }
    else if (n%3==1)
    {

    }
    else
    {

    }
    
}