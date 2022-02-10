#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli n, k;
vector<lli> nodes1, nodes2;
lli nChoose2( lli n)
{
    lli k =2;
    if (k > n) return 0;
    if (k * 2 > n) k = n-k;
    if (k == 0) return 1;

    lli result = n;
    for( lli i = 2; i <= k; ++i ) {
        result *= (n-i+1);
        result /= i;
    }
    return result;
}
void go_up1(lli u){
    if(u == 0){
        nodes1.push_back(0);
        return;
    }
    nodes1.push_back(u);
    lli v = (u-1)/k;
    go_up1(v);
}
void go_up2(lli u){
    if(u == 0){
        nodes2.push_back(0);
        return;
    }
    nodes2.push_back(u);
    lli v = (u-1)/k;
    go_up2(v);
}
lli dist(int x, int y)
{
    nodes1.clear(), nodes2.clear();
    lli cnt =0;
    go_up1(x-1);
    go_up2(y-1);
    for (lli i = nodes1.size()-1 ; i >=0 ; i--)
    {
            lli ind = nodes2.size() - (nodes1.size() - i);
            if(ind < nodes2.size() && ind >= 0 && nodes1[i] == nodes2[ind]) 
            {
                cnt++;
            }
        }
        return (nodes2.size()+nodes1.size()-(2*cnt));
}
int main()
{
    lli n,q, x, y;
    cin>>n>>q;
    while(q--)
    {
        cin>>x>>y;
        lli dis = dist(x,y);
        lli res = n + nChoose2(dis);
    }
}