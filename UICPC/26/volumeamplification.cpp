#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=10000007;
bool arr[N];
int main()
{
    int T; cin>>T;
    while (T--)
    {
        int a; cin>>a;
        ll target; cin>>target;
        fill_n(arr,a,false);
        ll temp; cin>>temp;
        bool resflag=true;
        ll mul;
        arr[1]=true;
        arr[temp]=true;
        for (int i = 1; i < a; i++)
        {
            cin>>temp;
            for (ll j = target-1; j>=1; j--)
            {
                if (arr[j]==true)
                {
                    mul=j*temp;
                    if (mul>target)
                    {
                        continue;
                    }
                    else
                    {
                        arr[mul]=true;
                    }
                }
            }
        }
        for (int i = target; i>=1; i--)
        {
            if (arr[i])
            {
                cout<<i<<'\n';
                break;
            }
        }
    }
}