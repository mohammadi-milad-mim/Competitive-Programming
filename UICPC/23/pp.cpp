// C++ program to to implement
// the above approach
 
#include <bits/stdc++.h>
using namespace std;
 
// Function to find the Longest Common
// Subsequence between the two arrays
int LCS(vector<int>& firstArr,
        vector<int>& secondArr)
{
 
    // Maps elements of firstArr[]
    // to their respective indices
    unordered_map<int, int> mp;
 
    // Traverse the array firstArr[]
    for (int i = 0; i < firstArr.size(); i++) {
        mp[firstArr[i]] = i + 1;
    }
 
    // Stores the indices of common elements
    // between firstArr[] and secondArr[]
    vector<int> tempArr;
 
    // Traverse the array secondArr[]
    for (int i = 0; i < secondArr.size(); i++) {
 
        // If current element exists in the Map
        if (mp.find(secondArr[i]) != mp.end()) {
 
            tempArr.push_back(mp[secondArr[i]]);
        }
    }
 
    // Stores lIS from tempArr[]
    vector<int> tail;
 
    tail.push_back(tempArr[0]);
 
    for (int i = 1; i < tempArr.size(); i++) {
 
        if (tempArr[i] > tail.back())
            tail.push_back(tempArr[i]);
 
        else if (tempArr[i] < tail[0])
            tail[0] = tempArr[i];
 
        else {
            auto it = lower_bound(tail.begin(),
                                  tail.end(),
                                  tempArr[i]);
            *it = tempArr[i];
        }
    }
    return (int)tail.size();
}
 
// Driver Code
int main()
{
    vector<int> firstArr = { 3, 5, 1, 8 };
    vector<int> secondArr = { 3, 3, 5, 3, 8 };
    cout << LCS(firstArr, secondArr);
    return 0;
}