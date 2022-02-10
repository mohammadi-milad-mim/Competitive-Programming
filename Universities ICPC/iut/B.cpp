#include <bits/stdc++.h>
 using namespace std;
long distance(long curr, long dist, vector<bool> state){
    long min_ind = min(curr, dist);
    long max_ind = max(curr, dist);
    int counter = 0;
    for(int i= min_ind ;i < max_ind; i++ ){
        if (state[i]) counter++;
    }
    return abs(curr - dist - counter);
}

 int main(){
        int n;cin>>n;
        vector < bool>  state;
        vector < long> mp[n];
        int t, curr = 0, total_sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin>>t;
            state.push_back(false);
            mp[t-1].push_back(i);
        }
        // cout<<"yes";
        for (int i = 0; i < n; i++){
            if (mp[i].size() >= 1){
                priority_queue < pair<long, long> ,vector<pair<long, long>>, greater<pair<long, long>>> tmp_vector;
                for (int j = 0; mp[i].size(); j++){
                    cout<<"in for\n";
                    tmp_vector.push(make_pair(distance(curr, mp[i][j], state),mp[i][j] ));
                }
                cout<<"before while\n";
                while (true){      
                    if (tmp_vector.size() > 0){
                        cout<<"in LOOOOP\n";
                        long index = tmp_vector.top().second;
                        long distance = tmp_vector.top().first;
                        total_sum += distance;
                        state[index] = true;
                        curr = index;
                        tmp_vector.pop();
                        // total_sum += tmp_vector
                    }

                    else break;
                }
            }
        }
        cout<< total_sum;
 }