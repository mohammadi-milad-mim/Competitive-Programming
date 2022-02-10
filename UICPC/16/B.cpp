#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
// std::cout << std::setprecision(3) << std::fixed << doubllle;
typedef unsigned long long int ulli;
// sort(arr, arr + n, greater<int>());
//c = ::tolower(c);
//for (int i = 0; i < s.size(); i++) {
//s[i] = tolower(s[i]);
int MAP [1000000000 + 5];

lli n, c, mx=-1;
pair<lli, lli> a[100000 + 5];
int main() {
  //lli* MAP = new lli[1000000000 + 5];
  fill_n(MAP, mx+5, 0);
  cin >> n >> c;
  for (int i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
    mx = max(a[i].second, mx);
  }
  fill_n(MAP, mx + 5, 0);
  sort(a, a + n);
  lli busy = 0, count=0;
  int j = 0;
  for (int i = 0; i < mx + 5; i++) {
    if (MAP[i] > 0) {
      MAP[i]--;
      busy--;
    }
    if (a[j].first == i) {
      if (busy < c) {
        MAP[a[j].second]++;
        busy++;
        count++;
      }
      j++;
    }
    
  }
  cout << count;
}