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
vi ind, ANS;

// Sum of waiting times in [l,r] for person i.
int sum(int l, int r, int i){
    if(l <= r)return CS[i][r+1] - CS[i][l];
    return CS[i][n] - CS[i][l] + CS[i][r+1];
}

// Does i catch up to j if they start at si,sj?
bool collide(int i, int j, int si, int sj){
    for(int crash = sj; crash != si; crash = (crash+1)%n){
        if(sum(si,crash-1,i) < sum(sj,crash,j) - D[crash])return 1;
    }
    return 0;
}

// Find a solution starting at 'start' with permutation 'ind':
bool solve(int start){
    ANS[ind[0]] = start;
    int now = (start+1)%n;
    rep(i,1,k){
        if(now == start)return 0;
        // Could replace with a binary search:
        while(collide(ind[i-1], ind[i], ANS[ind[i-1]], now)){
            now = (now+1)%n;
            if(now == start)return 0;
        }
        ANS[ind[i]] = now;
        now = (now+1)%n;
    }
    if(collide(ind[k-1], ind[0], ANS[ind[k-1]], start))return 0;
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
    int fk = 1;
    rep(c1,0,k){
        ind.push_back(c1);
        ANS.push_back(-1);
        fk *= (c1+1);
    }
    rep(_,0,fk){
        if(ind[0] == 0){
            rep(start,0,n){
                if(solve(start)){
                    rep(c1,0,k){
                        if (c1 != 0) cout << " ";
                        cout << ANS[c1]+1;
                    }cout << "\n";
                    return 0;
                }
            }
        }
        next_permutation(all(ind));
    }
    cout << "impossible\n";
    return 0;
}

