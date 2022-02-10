#include<bits/stdc++.h>
using namespace std;
 
// Number of vertices in the graph
const int n=10;
 
void printSolution(int color[]);
 
// check if the colored
// graph is safe or not
bool isSafe(bool graph[n][n], int color[])
{
    // check for every edge
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (graph[i][j] && color[j] == color[i])
                return false;
    return true;
}
 
/* This function solves the m Coloring
problem using recursion. It returns
false if the m colours cannot be assigned,
otherwise, return true and prints
assignments of colours to all vertices.
Please note that there may be more than
one solutions, this function prints one
of the feasible solutions.*/
bool graphColoring(bool graph[n][n], int m, int i,
                int color[n])
{
    // if current index reached end
    if (i == n) {
       
        // if coloring is safe
        if (isSafe(graph, color)) {
           
            // Print the solution
            printSolution(color);
            return true;
        }
        return false;
    }
 
    // Assign each color from 1 to m
    for (int j = 1; j <= m; j++) {
        color[i] = j;
 
        // Recur of the rest vertices
        if (graphColoring(graph, m, i + 1, color))
            return true;
 
        color[i] = 0;
    }
 
    return false;
}
 
/* A utility function to print solution */
void printSolution(int color[])
{
    //cout << "Solution Exists:" " Following are the assigned colors \n";
    for (int i = 0; i < n; i++)
        cout <<i+1<<"  " << color[i]+1<<endl;
}
 
// Driver code
int main()
{
    int N; cin>>N;
    bool graph[n][n];
    string s;
    while(cin>>s)
    {
        int i=0;
        int a=0;
        while(s[i]!='-')
        {
            //cout<<int(s[i])-48<<endl;
            a = (a*10)+(int(s[i])-48);
            //cout<<a<<endl;
            i++;
        }
        //cout<<endl;
        i++;
        int b=0;
        while(i<s.length())
        {
            //cout<<int(s[i])-48<<endl;
            b = (b*10)+(int(s[i])-48);
            //cout<<b<<endl;
            i++;
        }
        //cout<<a-1<<" "<<b-1<<endl;
       graph[a][b]=true;
       graph[b][a]=true;
    }
    int m = 3;
    int color[N];
    for (int i = 0; i < N; i++)
        color[i] = 0;
 
    if (!graphColoring(graph, m, 0, color))
        cout << "Solution does not exist";
 
    return 0;
}
 
// This code is contributed by shivanisinghss2110