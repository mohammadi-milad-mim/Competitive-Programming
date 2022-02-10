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

int n,k;
vi D;
vector<vi> T(10, vi());
vector<vi> CS(10, vi());
vi ANS;

// Sum of waiting times in [l,r] for person i.
int sum(int l, int r, int i){
    if(l <= r)return CS[i][r+1] - CS[i][l];
    return CS[i][n] - CS[i][l] + CS[i][r+1];
}

// Does i catch up to j if they start at si,sj?
bool collide(int i, int j, int si, int sj){
    if(i == j)return 0;
    if(si == sj)return 1;
    for(int crash = sj; crash != si; crash = (crash+1)%n){
        if(sum(si,crash-1,i) < sum(sj,crash,j) - D[crash])return 1;
    }
    return 0;
}

bool valid(){
    rep(c1,0,k){
        rep(c2,0,k){
            if(collide(c1, c2, ANS[c1], ANS[c2]))return 0;
        }
    }
    return 1;
}

int main() {

    cin >> n;
    k = 3;
    rep(c1,0,n){
        int a;
        cin >> a;
        D.push_back(a);
    }
    rep(c1,0,k){
        CS[c1].push_back(0);
        rep(c2,0,n){
            int a;
            cin >> a;
            a += D[c2];
            T[c1].push_back(a);
            CS[c1].push_back(CS[c1][c2]+a);
        }
    }

    rep(c1,0,k){
        ANS.push_back(-1);
    }
    rep(c1,0,n){
        rep(c2,0,n){
            rep(c3,0,n){
                ANS[0] = c1;
                ANS[1] = c2;
                ANS[2] = c3;
                if(valid()){
                    cout << ANS[0]+1 << " " << ANS[1]+1 << " " << ANS[2]+1 << "\n";
                    return 0;
                }
            }
        }
    }
    cout << "impossible\n";
    return 0;
}

