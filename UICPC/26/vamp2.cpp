#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=10000007;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin>>T;
    while (T--)
    {
        int a; cin>>a;
        int target; cin>>target;
        unordered_set<int> setOfmul;
        setOfmul.clear();
        int closest = 1;
        setOfmul.insert(1);
        int temp; cin>>temp;
        int mul;
        if (temp<=target)
        {
            closest=temp;
        }
        setOfmul.insert(temp);
        for (int i = 1; i < a; i++)
        {
            cin>>temp;
            vector<int> newMuls;
            for (auto it = setOfmul.begin(); it != setOfmul.end(); ++it)
            {
                mul = (*it) * temp;
                if (mul<=target)
                {
                    if (mul>closest)
                    {
                        closest = mul;
                    }
                    newMuls.push_back(mul);
                }
            }
            for (auto mu:newMuls)
            {
                setOfmul.insert(mu);
            }
        }
        cout << closest << '\n';
    }
}