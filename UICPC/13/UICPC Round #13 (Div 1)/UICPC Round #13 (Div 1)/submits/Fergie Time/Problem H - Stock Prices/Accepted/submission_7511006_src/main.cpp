#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define watch(x) cout << #x << " : " << x << endl;
#define pll pair<ll, ll>
const ll mod = 1e9 + 7;
const ll maxN = 1000;

int main()
{
    ll t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        map<ll, ll> buymap;
        map<ll, ll> sellmap;
//        priority_queue<ll> buypq;
        set<ll, greater<ll>> buySet;
//        priority_queue<ll, vector<ll>, greater<ll>> sellpq;
        set<ll> sellSet;
        ll ask = LLONG_MAX, bid = -1, stock = -1;
        while(n--)
        {
            string buy_sell;
            cin >> buy_sell;
            ll shares;
            cin >> shares;
            string waste1, waste2;
            cin >> waste1 >> waste2;
            ll price;
            cin >> price;

            if(buy_sell == "buy")
            {
                if(buymap.find(price) == buymap.end())
                {
                    buymap[price] = shares;
                }
                else
                {
                    buymap[price] += shares;
                }
                buySet.insert(price);
            }
            else
            {
                if(sellmap.find(price) == sellmap.end())
                {
                    sellmap[price] = shares;
                }
                else
                {
                    sellmap[price] += shares;
                }
                sellSet.insert(price);
            }

            if(buySet.size() != 0 && sellSet.size() != 0)
            {
                while((buySet.size() != 0 && sellSet.size() != 0) && (*(buySet.begin()) >= *(sellSet.begin())))
                {
                    ll sellcount = sellmap[*(sellSet.begin())];
                    ll buycount = buymap[*(buySet.begin())];

                    if(sellcount < buycount)
                    {
                        ll key = *(sellSet.begin());
                        ll value = sellmap[key];

                        if(ask == *(sellSet.begin()))
                        {
                            ask = LLONG_MAX;
                        }
                        sellSet.erase(sellSet.begin());
                        sellmap.erase(key);

                        buymap[*(buySet.begin())] -= value;
                        stock = key;
                    }
                    else if(buycount < sellcount)
                    {
                        ll key = *(buySet.begin());
                        ll value = buymap[key];

                        if(bid == *(buySet.begin()))
                        {
                            bid = -1;
                        }

                        buySet.erase(buySet.begin());
                        buymap.erase(key);

                        sellmap[*(sellSet.begin())] -= value;
                        stock = *(sellSet.begin());
                    }
                    else
                    {
                        ll sellkey = *(sellSet.begin());
                        ll buykey  = *(buySet.begin());

                        if(ask == *(sellSet.begin()))
                        {
                            ask = LLONG_MAX;
                        }
                        if(bid == *(buySet.begin()))
                        {
                            bid = -1;
                        }
                        sellSet.erase(sellSet.begin());
                        sellmap.erase(sellkey);
                        buySet.erase(buySet.begin());
                        buymap.erase(buykey);
                        stock = sellkey;
                    }
                }
            }
            ask = (sellSet.size())? min(ask, *(sellSet.begin())) : LLONG_MAX;
            bid = (buySet.size())? max(bid, *(buySet.begin())) : -1;
            cout << ((ask != LLONG_MAX)? to_string(ask) : "-") << " " << ((bid != -1)? to_string(bid): "-") << " " << ((stock != -1)? to_string(stock): "-") << endl;
        }
    }
    return 0;
}