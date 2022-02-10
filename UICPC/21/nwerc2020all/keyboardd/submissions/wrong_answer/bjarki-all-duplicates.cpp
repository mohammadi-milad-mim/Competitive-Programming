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

    set<char> dups;
    for (size_t i = 1; i < after.size(); i++) {
        if (after[i-1] == after[i]) {
            dups.insert(after[i]);
        }
    }

    iter(it,dups) {
        cout << *it;
    }
    cout << endl;

    return 0;
}

