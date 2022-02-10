#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin>>n;
  vector<tuple<int,int,int>> lines(n);
  for (int i=0; i<n; i++)
    cin>>get<0>(lines[i])>>get<1>(lines[i]),
    get<2>(lines[i])=i;
  sort(lines.begin(),lines.end());

  typedef pair<float,pair<int,int>> T;
  priority_queue<T,vector<T>,greater<T>> upcoming;
  auto consider=[&upcoming,&lines](int a,int b){
    if (get<1>(lines[a])>get<1>(lines[b]))
      upcoming.push({
        (long double)(get<0>(lines[b])-get<0>(lines[a]))/
        (long double)(get<1>(lines[a])-get<1>(lines[b])), {a,b}});
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

  cout<<active.size(); for (auto i: active) cout<<" "<<get<2>(lines[i])+1; cout<<endl;
}
