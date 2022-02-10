#include <bits/stdc++.h>
using namespace std;
#define MAXN  1000007
long long int arr[MAXN];
long long int psum[MAXN];
int spf[MAXN];
set<pair<int,int>> se;
long long int jumps[MAXN];
void sieve()
{
    spf[1] = 1;
    for (int i=2; i<MAXN; i++)
        spf[i] = i;
    for (int i=4; i<MAXN; i+=2)
        spf[i] = 2;
    for (int i=3; i*i<MAXN; i++)
    {
        if (spf[i] == i)
        {
            for (int j=i*i; j<MAXN; j+=i)
                if (spf[j]==j)
                    spf[j] = i;
        }
    }
}
vector<int> getFactorization(int x)
{
    vector<int> ret;
    while (x != 1)
    {
        ret.push_back(spf[x]);
        x = x / spf[x];
    }
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int N,K; cin>>N>>K;
    sieve();
    long long nOne = 0;
    long long int jump;
    for (long long int i = 0; i < K; i++)
    {
        cin>>jump;
        if (jump==1)
        {
            nOne+=1;
        }
        vector<int> temp = getFactorization(jump);
        for (auto i:temp)
        {
            jumps[i]++;
        }
    }
    fill_n(arr,N,nOne);
    long long int theJump,nJumps;
    for (long long int i = 2; i < N; i++)
    {
        nJumps=jumps[i];
        if (nJumps)
        {
            theJump=i;
            for (long long int  j = 0; j < N; j+=theJump)
            {
                arr[j]+=nJumps;
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        cout<<jumps[i]<<" ";
    }
    cout<<endl;
    for (int i = 0; i < N; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    psum[0]=arr[0];
    for (long long int i = 1; i < N; i++)
    {
        psum[i]=psum[i-1]+arr[i];
    }
    long long int Q; cin>>Q;
    long long int x,y;
    for (long long int i = 0; i < Q; i++)
    {
        cin>>x>>y;
        cout<<psum[y]-psum[x-1]<<'\n';
    }
}