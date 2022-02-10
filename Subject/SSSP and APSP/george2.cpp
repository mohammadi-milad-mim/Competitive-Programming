#include <bits/stdc++.h>
using namespace std;

// SSSP, Dijkstra

// Dijkstra's Algorithm

// O(V + E * logV)

#define inf INT_MAX

pair<int,int> tim[1003][1003]; // {weight, dst}
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int dis[1003];

int main(){