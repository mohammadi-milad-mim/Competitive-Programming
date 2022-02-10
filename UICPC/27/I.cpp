#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n; cin>>n;
	int a,b,x,res;
    int c[n];
	vector <int> vi;
	for(int i=0;i<n;i++)
    {
        cin>>a; a--;
        c[a]=i;
	}
    for(int i=0;i<n;i++)
    {
        cin>>b; b--;
        x=c[b];
        auto it=lower_bound(vi.begin(),vi.end(),x);
        if(it==vi.end())
        {
            vi.push_back(x);
        }
        else
        {
            vi[it-vi.begin()]=x;
        }
    }
    res=vi.size()+1;
    cout<<2<<" "<<res;
}