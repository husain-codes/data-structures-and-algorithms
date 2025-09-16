#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>

using namespace std;

// ------------------- Node Structure -------------------
// Represents a graph node with a value and its list of neighbours
class Node {
public:
    int val;
    vector<Node*> neighbours;
    Node() : val(0), neighbours(vector<Node*>()) {}
    Node(int _val) : val(_val), neighbours(vector<Node*>()) {}
    Node(int _val, vector<Node*> _neighbours) : val(_val), neighbours(_neighbours) {}
};


// ------------------- Clone using BFS -------------------
class CloneBFS {
public:
    // Clones the graph starting from the given node using BFS traversal.
    // Time Complexity: O(V + E)   (we visit all nodes and edges once)
    // Space Complexity: O(V)     (for the queue + visited map)
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        unordered_map<Node*, Node*> visited; // maps original node -> cloned node
        return BFS(node, visited);
    }

private:
    // Helper BFS function
    Node* BFS(Node* node, unordered_map<Node*, Node*>& visited) {
        // Create clone of the starting node
        visited[node] = new Node(node->val);
        queue<Node*> q;
        q.push(node);

        while (!q.empty()) {
            Node* top = q.front();
            q.pop();

            // Traverse neighbours
            for (auto i : top->neighbours) {
                // If neighbour not visited, create its clone
                if (!visited.count(i)) {
                    visited[i] = new Node(i->val);
                    q.push(i);
                }
                // Link clone of current node with clone of neighbour
                visited[top]->neighbours.push_back(visited[i]);
            }
        }
        return visited[node];
    }
};


// ------------------- Clone using DFS -------------------
class CloneDFS {
public:
    // Clones the graph starting from the given node using DFS traversal.
    // Time Complexity: O(V + E)   (we visit all nodes and edges once)
    // Space Complexity: O(V)     (for recursion stack + visited map)
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        unordered_map<Node*, Node*> visited; // maps original node -> cloned node
        return DFS(node, visited);
    }

private:
    // Helper DFS function
    Node* DFS(Node* node, unordered_map<Node*, Node*>& visited) {
        // If already cloned, return the clone
        if (visited.count(node)) return visited[node];

        // Create clone for the node
        visited[node] = new Node(node->val);

        // Recurse for neighbours
        for (auto i : node->neighbours) {
            visited[node]->neighbours.push_back(DFS(i, visited));
        }
        return visited[node];
    }
};


// ------------------- Utility: Print Graph -------------------
// Prints adjacency list of a graph using DFS
// Helps verify correctness of cloning
void printGraph(Node* node, unordered_map<Node*, bool>& visited) {
    if (!node || visited[node]) return;
    visited[node] = true;

    cout << "Node " << node->val << " -> ";
    for (auto n : node->neighbours) {
        cout << n->val << " ";
    }
    cout << endl;

    for (auto n : node->neighbours) {
        printGraph(n, visited);
    }
}


// ------------------- Driver Code -------------------
int main() {
    // Create a simple graph: 1 -- 2 -- 3 -- 4 (square cycle)
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);

    n1->neighbours.push_back(n2);
    n2->neighbours.push_back(n1);

    n2->neighbours.push_back(n3);
    n3->neighbours.push_back(n2);

    n3->neighbours.push_back(n4);
    n4->neighbours.push_back(n3);

    n4->neighbours.push_back(n1);
    n1->neighbours.push_back(n4);

    cout << "Original Graph:" << endl;
    unordered_map<Node*, bool> visited1;
    printGraph(n1, visited1);

    // Clone using BFS
    CloneBFS bfsCloner;
    Node* bfsClone = bfsCloner.cloneGraph(n1);

    cout << "\nCloned Graph using BFS:" << endl;
    unordered_map<Node*, bool> visited2;
    printGraph(bfsClone, visited2);

    // Clone using DFS
    CloneDFS dfsCloner;
    Node* dfsClone = dfsCloner.cloneGraph(n1);

    cout << "\nCloned Graph using DFS:" << endl;
    unordered_map<Node*, bool> visited3;
    printGraph(dfsClone, visited3);

    return 0;
}
