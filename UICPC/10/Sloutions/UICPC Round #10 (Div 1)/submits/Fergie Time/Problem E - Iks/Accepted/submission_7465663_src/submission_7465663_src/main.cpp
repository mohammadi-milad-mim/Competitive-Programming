#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define ll long long
#define ld long double
#define pll pair<ll, ll>
#define pld pair<ld, ld>
#define watch(x) cout << #x << " : " << x << endl
const ll mod = 1e9 + 7;
const ll maxN = 1000;
string waste;
void watchstack(stack<ll> s)
{
    while(s.size())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}
vector<ll> getPrimes(ll maxn)
{
    ll maxPrime = maxn;
    vector<bool> isPrime(maxPrime + 1, true);
    isPrime[1] = false;
    for(ll i = 2; i <= maxPrime; i++)
    {
        if(isPrime[i])
        {
            for(ll num = i * i; num <= maxPrime; num += i)
            {
                isPrime[num] = false;
            }
        }
    }
    vector<ll> primes;
    for(ll i = 1; i < isPrime.size(); i++)
    {
        if(isPrime[i])
        {
            primes.push_back(i);
        }
    }
    return primes;
}
int main()
{
    ll n,t=0,gsd=1;
    cin>>n;
    ll *arr=new ll[n];
    for(ll i=0;i<n;i++)
    {
        cin>>arr[i];

    }
    vector<ll> primes;
    primes=getPrimes(1000000);

    for(ll i=0;i<primes.size();i++)
    {
         vector<ll> tedad(n,0);
         ll holet=0;
        for(ll j=0;j<n;j++)
        {

           while(arr[j]%primes[i]==0){
               tedad[j]+=1;
               arr[j]=arr[j]/primes[i];

           }
           holet +=tedad[j];
        }
        ll x;
        x=holet/n;
        gsd *=(pow(primes[i],x));
        for(ll r=0;r<n;r++)
        {
            if(tedad[r]<x)
            {
                t +=(x-tedad[r]);
            }
        }

    }

    cout<<gsd<<" "<<t<<endl;
}
