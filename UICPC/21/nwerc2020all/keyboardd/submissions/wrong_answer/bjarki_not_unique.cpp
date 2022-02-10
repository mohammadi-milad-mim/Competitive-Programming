#include <iostream>
#include <string>
#include <set>
#include <cassert>
using namespace std;
#define rep(i,a,b) for (auto i=(a); i<(b); ++i)
#define iter(it,c) for (auto it = (c).begin(); it != (c).end(); ++it)
typedef long long ll;
const int INF = 2147483647;

int main() {
    string before, after;
    getline(cin, before);
    getline(cin, after);

    set<char> dups(before.begin(), before.end());

    size_t j = 0;
    for (size_t i = 0; i < before.size(); ) {
        char c = before[i];
        int l = 0, r = 0;
        while (i < before.size() && before[i] == c) i++, l++;
        while (j < after.size() && after[j] == c) j++, r++;
        assert(r >= l);

        if (l == r) {
            dups.erase(c);
        }
    }
    assert(j == after.size());

    iter(it,dups) {
        cout << *it;
    }
    iter(it,dups) {
        cout << *it;
    }
    cout << endl;

    return 0;
}

