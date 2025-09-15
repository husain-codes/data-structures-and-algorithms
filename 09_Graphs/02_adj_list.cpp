#include<iostream>
#include<vector>
#include<tuple>

using namespace std;

// Function to create adjacency list (unweighted, undirected)
vector<vector<int>> createAdjList(int V, vector<pair<int,int>> &edges) {
	vector<vector<int>> adj(V);
	
	for(auto &e : edges) {
		int u = e.first;
		int v = e.second;
		
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	return adj;
}

// Function to create weighted adjacency list (undirected)
vector<vector<pair<int,int>>> createWeightedAdjList(int V, vector<tuple<int,int,int>> &edges) {
	vector<vector<pair<int,int>>> adj(V);
	
	for (auto &e: edges) {
		int u , v ,w;
		tie(u,v,w) = e;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}
	return adj;
}

void printAdjList(vector<vector<int>> &adj) {
	for(int i = 0; i < adj.size(); i++){
		cout << i << "->";
		for (auto j : adj[i]) {
			cout << j << " "; 
		}
		cout << endl;
	}
}

void printWeightedAdjList(vector<vector<pair<int,int>>> &adj) {
	for(int i = 0; i < adj.size(); i++){
		cout << i << "->";
		for (auto j : adj[i]) {
			cout << j.first << "(" << j.second << ")" << " "; 
		}
		cout << endl;
	}
}

int main() {
	vector<pair<int,int>> edges = {{0,1}, {1,2}, {0,2}};
	vector<vector<int>> adjList = createAdjList(3,edges);
	printAdjList(adjList);
	
	cout << endl << endl;
	vector<tuple<int,int,int>> wEdges = {{0,1, 5}, {1,2,3}, {0,2,2}};
	vector<vector<pair<int,int>>> wAdjList = createWeightedAdjList(3,wEdges);
	printWeightedAdjList(wAdjList);
	return 0;
}