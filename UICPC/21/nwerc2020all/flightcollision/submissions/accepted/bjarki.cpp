#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for (auto i=(a); i<(b); ++i)
#define iter(it,c) for (auto it = (c).begin(); it != (c).end(); ++it)
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef long long ll;
const int INF = 2147483647;

template <class T> struct fraction {
  T gcd(T a, T b) { return b == T(0) ? a : gcd(b, a % b); }
  T n, d;
  fraction(T n_=T(0), T d_=T(1)) {
    assert(d_ != 0);
    n = n_, d = d_;
    if (d < T(0)) n = -n, d = -d;
    T g = gcd(abs(n), abs(d));
    n /= g, d /= g; }
  fraction(const fraction<T>& other)
    : n(other.n), d(other.d) { }
  fraction<T> operator +(const fraction<T>& other) const {
    return fraction<T>(n * other.d + other.n * d,
                       d * other.d);}
  fraction<T> operator -(const fraction<T>& other) const {
    return fraction<T>(n * other.d - other.n * d,
                       d * other.d); }
  fraction<T> operator *(const fraction<T>& other) const {
    return fraction<T>(n * other.n, d * other.d); }
  fraction<T> operator /(const fraction<T>& other) const {
    return fraction<T>(n * other.d, d * other.n); }
  bool operator <(const fraction<T>& other) const {
    return n * other.d < other.n * d; }
  bool operator <=(const fraction<T>& other) const {
    return !(other < *this); }
  bool operator >(const fraction<T>& other) const {
    return other < *this; }
  bool operator >=(const fraction<T>& other) const {
    return !(*this < other); }
  bool operator ==(const fraction<T>& other) const {
    return n == other.n && d == other.d; }
  bool operator !=(const fraction<T>& other) const {
    return !(*this == other); } };

using rat = fraction<ll>;

bool intersect(ii a, ii b, rat &x) {
    assert(a.first != b.first);
    if (a.second == b.second) {
        return false;
    }

    x = rat(b.first - a.first, a.second - b.second);
    return x >= 0;
}

int main() {
    int n;
    cin >> n;

    map<int,ii> seq;
    vi remove;
    rep(i,0,n) {
        int x, v;
        cin >> x >> v;
        if (seq.find(x) != seq.end()) {
            remove.push_back(x);
        }
        seq[x] = ii(v, i);
    }

    iter(it,remove) {
        seq.erase(*it);
    }

    priority_queue<pair<rat, ii>, vector<pair<rat,ii> >, greater<pair<rat,ii> > > pq;

    auto it = seq.begin(),
         jt = it;
    while (++jt != seq.end()) {
        rat t;
        if (intersect(ii(it->first, it->second.first), ii(jt->first, jt->second.first), t)) {
            pq.push(make_pair(t, make_pair(it->first, jt->first)));
        }

        ++it;
    }

    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();

        if (seq.find(cur.second.first) != seq.end() && seq.find(cur.second.second) != seq.end()) {
            auto it = seq.find(cur.second.first),
                 jt = seq.find(cur.second.second),
                 kt = jt;
            ++kt;
            seq.erase(it);
            seq.erase(jt);
            if (kt != seq.end() && kt != seq.begin()) {
                it = kt;
                --it;
                jt = kt;

                rat t;
                if (intersect(ii(it->first, it->second.first), ii(jt->first, jt->second.first), t)) {
                    pq.push(make_pair(t, make_pair(it->first, jt->first)));
                }
            }
        }
    }

    cout << seq.size();
    vi res;
    iter(it,seq) {
        res.push_back(it->second.second);
    }
    sort(res.begin(), res.end());
    iter(it,res) {
        cout << " " << *it+1;
    }
    cout << endl;

    return 0;
}

