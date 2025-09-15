#include<iostream>
#include<vector>
#include<tuple>

using namespace std;

// Function to create adjacency matrix
vector<vector<int>> createAdjMatrix(int V , vector<pair<int,int>> &edges) {
    
    // Step 1: Create V x V matrix initialized with 0
    vector<vector<int>> adj(V , vector<int>(V,0));
    
    // Step 2: Loop through all edges
    for(auto &e :edges) {
        int u = e.first;   // first vertex of edge
        int v = e.second;  // second vertex of edge

        // Step 3: Mark edge in matrix
        adj[u][v] = 1;     
        adj[v][u] = 1;     // because graph is undirected
    }
    
    // Step 4: Return matrix
    return adj;
}

// Function to create Weightes adjacency matrix
vector<vector<int>> createWeightedAdjMatrix(int V , vector<tuple<int,int,int>> &edges) {
	// Step 1: Create V x V matrix initialized with 0
	vector<vector<int>> adj(V , vector<int>(V,-1));
	
	// Step 2: Loop through all edges
	for (auto &e : edges) {
		int u , v, w;
		tie(u,v,w) = e;
		adj[u][v] = w;
		adj[v][u] = w;
	}
	
	// Step 4: Return matrix
	return adj;
}
int main() {
	vector<pair<int,int>> edges;
	edges.push_back({0,1});
	edges.push_back({1,2});
	edges.push_back({0,2});
	vector<vector<int>> adj = createAdjMatrix(3,edges);
	
	for(auto i : adj) {
		for (auto k : i){
			cout << k << " ";
		}
		cout << endl;
	}
	
	vector<tuple<int,int,int>> wEdges = { {0,1,5}, {1,2,3}, {0,2,2} };
	vector<vector<int>> wAdj = createWeightedAdjMatrix (3,wEdges);
	cout << endl << endl;
	for(auto i : wAdj) {
		for (auto k : i){
			cout << k << " ";
		}
		cout << endl;
	}
}