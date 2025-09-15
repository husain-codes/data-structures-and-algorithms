#include<iostream>
#include<vector>
#include<queue>

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

// Time Complexity: O(N + E)
// N = number of nodes, E = number of edges
// BFS visits each node once and explores all its edges once.
void BFS(int N, int start, vector<vector<int>> &adj) {
    cout << "BFS: ";
    vector<int> visited(N,0);   // visited array to mark nodes that are already visited
    queue<int> q;               // queue to store nodes for BFS

    // Start BFS from the given start node
    q.push(start);
    visited[start] = 1;         // mark start node as visited

    while(!q.empty()) {
        int node = q.front();   // get the front node
        q.pop();                // remove it from queue
        cout << node << " ";    // print the current node

        // Explore all neighbors of the current node
        for (auto i : adj[node]) {
            if(visited[i]==0) {  // if neighbor is not visited
                visited[i] = 1;  // mark as visited
                q.push(i);       // push neighbor to queue
            }
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
    
    // Perform BFS starting from node 2
    BFS(3,2,adjList);
    return 0;
}
