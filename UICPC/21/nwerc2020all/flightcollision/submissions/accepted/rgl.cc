#include <bits/stdc++.h>
using namespace std;

struct Fraction{
  int64_t num,den;

  bool operator<(Fraction const &a)const{
    return den<0? Fraction{-num,-den}<a
        : a.den<0? (*this)<Fraction{-a.num,-a.den}
        : num*a.den<a.num*den;
  }
};

int main(){
  int n; cin>>n;
  vector<tuple<int,int,int>> lines(n);
  for (int i=0; i<n; i++)
    cin>>get<0>(lines[i])>>get<1>(lines[i]),
    get<2>(lines[i])=i;
  sort(lines.begin(),lines.end());

  typedef pair<Fraction,pair<int,int>> T;
  priority_queue<T,vector<T>,greater<T>> upcoming;
  auto consider=[&upcoming,&lines](int a,int b){
    if (get<1>(lines[a])>get<1>(lines[b]))
      upcoming.push({Fraction{
        get<0>(lines[b])-get<0>(lines[a]),
        get<1>(lines[a])-get<1>(lines[b])
      }, {a,b}});
  };

  set<int> active;
  for (int i=0; i<n; i++) active.insert(i), consider(i-1,i);

  while (not upcoming.empty()){
    int a=upcoming.top().second.first;
    int b=upcoming.top().second.second;
    upcoming.pop();
    if (active.count(a) and active.count(b)){
      active.erase(a);
      active.erase(b);
      auto pre=active.lower_bound(a);
      auto aft=active.upper_bound(b);
      if (pre!=active.begin() and aft!=active.end()) consider(*--pre,*aft);
    }
  }

  vector<int> res;
  for (auto i: active) res.push_back(get<2>(lines[i])+1);
  sort(res.begin(),res.end());
  cout<<res.size(); for (auto i: res) cout<<" "<<i; cout<<endl;
}
