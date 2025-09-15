#include<iostream>
#include<vector>

using namespace std;

// Function to create adjacency list (unweighted, undirected)
// V -> number of vertices
// edges -> list of edges (pairs of connected nodes)
vector<vector<int>> createAdjList(int V, vector<pair<int,int>> &edges) {
    vector<vector<int>> adj(V);  // create a vector of V vectors

    // Iterate through all edges
    for(auto &e : edges) {
        int u = e.first;
        int v = e.second;
        
        // For undirected graph, add each node to other's adjacency list
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    return adj;  // return adjacency list
}

// Function to print adjacency list
void printAdjList(vector<vector<int>> &adj) {
    for(int i = 0; i < adj.size(); i++){
        cout << i << " -> ";
        for (auto j : adj[i]) {
            cout << j << " ";  // print all neighbors of node i
        }
        cout << endl;
    }
}

/*
DFS (Depth-First Search) using adjacency list
Time Complexity: O(N + E)
    - N = number of nodes (each visited once)
    - E = number of edges (each edge explored once in adjacency list)
Space Complexity: O(N) for visited array + O(H) for recursion stack (H = max depth)
*/
void DFS(int N, int start , vector<vector<int>> adj) {
    static vector<int> visited(N,0);  // keeps track of visited nodes

    // Base condition: if node already visited, stop recursion
    if(visited[start] == 1)
        return;

    visited[start] = 1;             // mark node as visited
    cout << start << " ";            // process node (print)

    // Recurse for all unvisited neighbors
    for (auto i : adj[start]) {
        if (!visited[i]) {
            DFS(N,i,adj);
        }
    }
}

int main() {
    // List of edges (0-indexed) for a simple graph
    vector<pair<int,int>> edges = {{0,1}, {1,2}, {0,2}};
    
    // Create adjacency list
    vector<vector<int>> adjList = createAdjList(3,edges);
    
    // Print adjacency list
    printAdjList(adjList);
    
    // Perform DFS starting from node 2
    cout << "DFS: ";
    DFS(3,2,adjList);
    return 0;
}
