#include<bits/stdc++.h>
 
using namespace std;

int minSwaps(string arr, int n)
{

    pair<int, int> arrPos[n];
    for (int i = 0; i < n; i++)
    {
        arrPos[i].first = arr[i];
        arrPos[i].second = i;
    }

    sort(arrPos, arrPos + n);

    vector<bool> vis(n, false);
 
    int ans = 0;

    for (int i = 0; i < n; i++)
    {

        if (vis[i] || arrPos[i].second == i)
            continue;
        int cycle_size = 0;
        int j = i;
        while (!vis[j])
        {
            vis[j] = 1;
 
            j = arrPos[j].second;
            cycle_size++;
        }
 
        if (cycle_size > 0)
        {
            ans += (cycle_size - 1);
        }
    }
 
    return ans;
}
 
int main()
{
    int n; cin>>n;
    string st;
    string st1,st2,st3,st4,st,st6=st;
    cin>>st;
    //ABC
    int mi = minSwaps(st1, n);
    //ACB
    replace( st2.begin(), st2.end(), 'B', 'D');
    replace( st2.begin(), st2.end(), 'C', 'B');
    replace( st2.begin(), st2.end(), 'D', 'B');
    mi = min(mi,minSwaps(st2, n));
    //BCA
    replace( st.begin(), st.end(), 'B', 'D');
    replace( st.begin(), st.end(), 'A', 'B');
    
    replace( st.begin(), st.end(), 'C', 'E');
    replace( st.begin(), st.end(), 'E', 'A');
    replace( st.begin(), st.end(), 'D', 'B');
    mi = min(mi,minSwaps(st, n));
    //BAC
    replace( st.begin(), st.end(), 'B', 'D');
    replace( st.begin(), st.end(), 'C', 'B');
    replace( st.begin(), st.end(), 'D', 'B');
    mi = min(mi,minSwaps(st, n));
    //CAB
    replace( st.begin(), st.end(), 'B', 'D');
    replace( st.begin(), st.end(), 'C', 'B');
    replace( st.begin(), st.end(), 'D', 'B');
    mi = min(mi,minSwaps(st, n));
    //CBA
    replace( st.begin(), st.end(), 'B', 'D');
    replace( st.begin(), st.end(), 'C', 'B');
    replace( st.begin(), st.end(), 'D', 'B');
    mi = min(mi,minSwaps(st, n));
    return 0;
}