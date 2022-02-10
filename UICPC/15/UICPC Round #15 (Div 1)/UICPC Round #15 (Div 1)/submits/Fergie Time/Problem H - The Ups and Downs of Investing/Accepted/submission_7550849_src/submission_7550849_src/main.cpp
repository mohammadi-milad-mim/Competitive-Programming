#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define watch(x) cout << #x << " : " << x << endl;
#define pll pair<ll, ll>
const ll mod = 1e9 + 7;
const ll maxN = 500;
vector<ll> a;
bool isPeak(ll index, ll n)
{
    for(ll i = index + 1; i < index + n; i++)
    {
        if(i >= a.size())
        {
            return false;
        }
        if(a[i] >= a[i - 1])
        {
            return false;
        }
    }
    for(ll i = index - 1; i > index - n; i--)
    {
        if(i < 0)
        {
            return false;
        }
        if(a[i] >= a[i + 1])
        {
            return false;
        }
    }
    return true;
}
bool isValley(ll index, ll m)
{
    for(ll i = index + 1; i < index + m; i++)
    {
        if(i >= a.size())
        {
            return false;
        }
        if(a[i] <= a[i - 1])
        {
            return false;
        }
    }
    for(ll i = index - 1; i > index - m; i--)
    {
        if(i < 0)
        {
            return false;
        }
        if(a[i] <= a[i + 1])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    ll s, n, m;
    cin >> s >> n >> m;
    a = vector<ll>(s);
    for(ll i = 0; i < s; i++)
    {
        cin >> a[i];
    }
    ll peaks = 0, valleys = 0;
    for(ll i = 0; i < s; i++)
    {
        peaks += isPeak(i, n);
        valleys += isValley(i, m);
    }
    cout << peaks << " " << valleys;
    return 0;
}