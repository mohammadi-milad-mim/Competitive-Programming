#include <iostream>
#include <queue>
#include <set>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;

bool will_intersect(pair<ll, ll>& p, pair<ll,ll>& q) {
    return p.second != q.second;
}

pair<ll,ll> intersect_y(pair<ll, ll>& p, pair<ll,ll>& q) {
   return make_pair(q.first - p.first, p.second - q.second);
}

bool gt(const pair<ll,ll>& a, const pair<ll,ll>& b) {
    return a.first * b.second > a.second * b.first; 
}

bool past(const pair<ll,ll>& a) {
    return a.first < 0 != a.second < 0;
}

int main() {
    int n;
    cin >> n;
    vector<pair<ll,ll> > d(n);
    vector<int> prev(n), next(n);
    int c, m;
    for (int i = 0; i < n; ++i) {
        cin >> c >> m;
        d[i] = make_pair(c, m);
    }
    set<int> alive;
    for (int i = 0; i < n; ++i) {
        prev[i] = i - 1;
        next[i] = i + 1;
    }
    next[n - 1] = -1;

    auto cmp = [](const pair<pair<int,int>, pair<ll,ll>>& a, const pair<pair<int,int>, pair<ll,ll>>& b) {
         return gt(a.second, b.second); };
    priority_queue<
        pair<pair<int, int>, pair<ll,ll>>,
        vector<pair<pair<int, int>, pair<ll,ll>>>,
        decltype(cmp)> collisions(cmp);
    set<int> dead;
    
    for (int i = 1; i < n; ++i) {
        if (will_intersect(d[i-1], d[i]) && !past(intersect_y(d[i-1], d[i]))) {
            collisions.push(make_pair(make_pair(i-1, i), intersect_y(d[i-1], d[i])));
        }
    }

    while(!collisions.empty()) {
        auto coll = collisions.top(); collisions.pop();
        pair<int,int> drones = coll.first;
        if (dead.count(drones.first) || dead.count(drones.second)) continue;

        dead.insert(drones.first);
        dead.insert(drones.second);

        int next_d = next[drones.second],
            prev_d = prev[drones.first];

        if (next_d >= 0) {
            prev[next_d] = prev_d;
        }
        if (prev_d >= 0) {
            next[prev_d] = next_d;
        }

        if (prev_d >= 0 && next_d >= 0) {
            if (will_intersect(d[prev_d], d[next_d]) && !past(intersect_y(d[prev_d], d[next_d]))) {
                collisions.push(make_pair(make_pair(prev_d, next_d), intersect_y(d[prev_d], d[next_d])));
            }
        }
    }
    cout << n - dead.size() << '\n';
    for (int i = 0; i < n; ++i) {
        if (!dead.count(i)) {
            cout << i + 1 << ' ';
        }
    }
    cout << '\n';
}
