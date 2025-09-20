#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
    Function: isReachable
    ---------------------
    Uses BFS to check if there is a path from `start` to `end` in the graph.

    Parameters:
        start   - starting vertex
        end     - target vertex
        adjList - adjacency list representation of the graph

    Returns:
        true if `end` is reachable from `start`, false otherwise

    Time Complexity:
        O(V + E) per BFS call, where V = number of vertices, E = number of edges
*/

bool isReachable(int start, int end, vector<vector<int>> &adjList) {
    vector<int> visited(adjList.size(), 0);
    queue<int> q;
    q.push(start);
    visited[start] = 1;

    while(!q.empty()) {
        int top = q.front(); q.pop();
        if(top == end) return true;

        for(auto i : adjList[top]) {
            if(!visited[i]) {
                visited[i] = 1;
                q.push(i);
            }
        }
    }

    return false;
}

/*
    Function: findRedundantConnection
    ---------------------------------
    Finds the edge that, when added to the graph, creates a cycle.
    Iteratively checks reachability before adding an edge.

    Parameters:
        edges - list of edges representing an undirected graph

    Returns:
        vector<int> containing the redundant edge

    Time Complexity:
        O(E * (V + E)) in the worst case
        - BFS is called for each edge
        - V = number of vertices, E = number of edges
*/

vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    int V = edges.size();
    vector<vector<int>> adjList(V + 1);

    for(auto &e : edges) {
        int u = e[0], v = e[1];
        if(isReachable(u, v, adjList)) {
            return {u, v};
        } else {
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
    }

    return {};
}

// Driver code
int main() {
    vector<vector<int>> edges = {
        {1,2}, {1,3}, {2,3}
    };

    vector<int> redundant = findRedundantConnection(edges);

    cout << "Redundant edge: ";
    for(auto x : redundant) cout << x << " ";
    cout << endl;

    return 0;
}
