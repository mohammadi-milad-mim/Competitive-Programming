void APUtil(vector<int> adj[], int u, bool visited[],
            int disc[], int low[], int& time, int parent,
            bool isAP[])
{
    int children = 0;
 

    visited[u] = true;
 

    disc[u] = low[u] = ++time;
 

    for (auto v : adj[u]) {

        if (!visited[v]) {
            children++;
            APUtil(adj, v, visited, disc, low, time, u, isAP);
 
            low[u] = min(low[u], low[v]);
 
            if (parent != -1 && low[v] >= disc[u])
                isAP[u] = true;
        }
 
        else if (v != parent)
            low[u] = min(low[u], disc[v]);
    }
 
    if (parent == -1 && children > 1)
        isAP[u] = true;
}
 
void AP(vector<int> adj[], int V, vector<int> res)
{
    int disc[V] = { 0 };
    int low[V];
    bool visited[V] = { false };
    bool isAP[V] = { false };
    int time = 0, par = -1;
 
    for (int u = 0; u < V; u++)
        if (!visited[u])
            APUtil(adj, u, visited, disc, low,
                   time, par, isAP);
 
    for (int u = 0; u < V; u++)
        if (isAP[u] == true)
            res.push_back(i);
}
 