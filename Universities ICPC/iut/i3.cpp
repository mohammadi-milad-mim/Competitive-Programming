#include <bits/stdc++.h>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int I,J; cin>>I>>J;
    long long int nums[I][J];
    for (int i = 0; i < I; i++)
    {
        for (int j = 0; j < J; j++)
        {
            cin>>nums[i][j];
        }
    }
    long long int  psum[I][J];
    for (int i = 0; i < I; i++)
    {
        fill_n(psum[i],J,0);
        psum[i][0]=nums[i][0];
        for (int j = 1; j < J; j++)
        {
            psum[i][j]=psum[i][j-1]+nums[i][j];
        }
    }
    int T; cin>>T;
    int rs,re,cs,ce;
    while (T--)
    {
        cin>>rs>>re>>cs>>ce;
        long long int fsum=0, tsum=0;
        for (int i = rs; i <= re; i++)
        {
            tsum=0;
            if (cs>=1)
            {
                tsum = psum[i][ce]-psum[i][cs-1];
            }
            else
            {
                tsum = psum[i][ce];
            }
            fsum+=tsum;
        }
        cout<<fsum<<endl;
    }
}