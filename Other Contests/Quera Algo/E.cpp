#include <bits/stdc++.h>
using namespace std;

template <typename T>
vector<int> sort_indexes(const vector<T> &v) 
{

  vector<int> idx(v.size());
  iota(idx.begin(), idx.end(), 0);
  stable_sort(idx.begin(), idx.end(),
       [&v](int i1, int i2) {return v[i1] < v[i2];});

  return idx;
}

int main()
{
    int n,t;cin>>n;
    if (n==1)
    {
        int a,b; cin>>a>>b;
        if (b>=a) cout<<1;
        else cout<<0;
    }
    else
    {
        vector<int> a,b,ai;
        for (int i = 0; i < n; i++)
        {
            cin>>t; a.push_back(t);
        }
        for (int i = 0; i < n; i++)
        {
            cin>>t; b.push_back(t);
        }
        ai = sort_indexes(a);
        int lma=1,i=1;
        while (i<n)
        {
            int i1 = ai[i-1]; int i2= ai[i];
            int a1 = a[i1]; int a2 = a[i2];
            int b1 = b[i1]; int b2 = b[i2];
            //cout<<a1<<" "<<a2<<" "<<b1<<" "<<b2<<" "<<endl;
            if (abs(b1-b2)>=(a2-a1))
            {
                lma++;
            }
            i++;
        }
        cout<<lma;
    }
    
}