#include <bits/stdc++.h>
using namespace std;


class Graph
{
    int V;    // No. of vertices
    list<int> *adj;    // A dynamic array of adjacency lists
public:
    // Constructor and destructor
    Graph(int V)   { this->V = V; adj = new list<int>[V]; }
    ~Graph()       { delete [] adj; }
 
    // function to add an edge to graph
    void addEdge(int v, int w);
 
    // Prints greedy coloring of the vertices
    void greedyColoring();
};
 
void Graph::addEdge(int v, int w)
{
    for (auto node:adj[v])
    {
        if (node == w)
        {
            return;
        }
    }
    adj[v].push_back(w);
    adj[w].push_back(v);  // Note: the graph is undirected
}
 
// Assigns colors (starting from 0) to all vertices and prints
// the assignment of colors
void Graph::greedyColoring()
{
    int result[V];
 
    // Assign the first color to first vertex
    result[0]  = 0;
 
    // Initialize remaining V-1 vertices as unassigned
    for (int u = 1; u < V; u++)
        result[u] = -1;  // no color is assigned to u
 
    // A temporary array to store the available colors. True
    // value of available[cr] would mean that the color cr is
    // assigned to one of its adjacent vertices
    bool available[V];
    for (int cr = 0; cr < V; cr++)
        available[cr] = false;
 
    // Assign colors to remaining V-1 vertices
    for (int u = 1; u < V; u++)
    {
        // Process all adjacent vertices and flag their colors
        // as unavailable
        list<int>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
            if (result[*i] != -1)
                available[result[*i]] = true;
 
        // Find the first available color
        int cr;
        for (cr = 0; cr < V; cr++)
            if (available[cr] == false)
                break;
 
        result[u] = cr; // Assign the found color
 
        // Reset the values back to false for the next iteration
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
            if (result[*i] != -1)
                available[result[*i]] = false;
    }
 
    // print the result
    for (int u = 0; u < V; u++)
        cout << u+1 <<" "<<result[u]+1 << '\n';
}
 
// Driver program to test above function
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin>>n;
    Graph g(n);
    string s;
    while(cin>>s)
    {
        int i=0;
        int a=0;
        while(s[i]!='-')
        {
            a = (a*10)+(int(s[i])-49);
            i++;
        }
        i++;
        int b=0;
        while(i<s.length())
        {
            b = (b*10)+(int(s[i])-49);
            i++;
        }
       g.addEdge(a,b);
    }
    g.greedyColoring();
}