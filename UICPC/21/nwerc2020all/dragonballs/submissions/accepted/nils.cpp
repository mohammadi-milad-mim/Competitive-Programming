#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;
typedef unsigned long long ull;

unsigned seed = chrono::system_clock::now().time_since_epoch().count();
mt19937 eng(seed);

ll random2(){
    return (1ll << 31ll)*eng()+eng();
}

struct pt{
    ll x,y;
};

const ll INF = ll(1e9)*ll(1e9);

const ll MAXC = 1000000;
const ll MINC = 0;

ll n;

ll ask(ll x, ll y){
    cout << x << " " << y << "\n";
    fflush(stdout);
    ll ans;
    cin >> ans;
    return ans;
}

int main() {
    cin >> n;

    rep(c1,0,n){
        ll D = INF;
        ll minx = MINC;
        ll maxx = MAXC;
        ll miny = MINC;
        ll maxy = MAXC;
        while(1){
            ll x = random2()%(maxx-minx+1)+minx;
            ll y = random2()%(maxy-miny+1)+miny;
            ll d = ask(x,y);
            ll dist = (ll(sqrt(d)));
            if(dist < D){
                D = dist;
                minx = max(MINC,x-dist);
                maxx = min(MAXC,x+dist);
                miny = max(MINC,y-dist);
                maxy = min(MAXC,y+dist);
            }
            if(d == 0)break;
        }
    }

    return 0;
}
