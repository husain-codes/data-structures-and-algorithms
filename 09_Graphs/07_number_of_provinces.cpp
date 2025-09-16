#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
 * DFS for adjacency matrix
 * Marks all nodes reachable from 'start' as visited.
 * Time Complexity: O(n^2)
 * Space Complexity: O(n)
 */
void DFS(int start, vector<vector<int>>& isConnected, vector<int> &visited) {
    visited[start] = 1;
    for (int j = 0; j < isConnected.size(); j++) {
        if (isConnected[start][j] == 1 && !visited[j]) {
            DFS(j, isConnected, visited);
        }
    }
}

/*
 * BFS for adjacency matrix
 * Time Complexity: O(n^2)
 * Space Complexity: O(n)
 */
void BFS(int start, vector<vector<int>>& isConnected, vector<int> &visited) {
    visited[start] = 1;
    queue<int> q;
    q.push(start);
    
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        for(int j = 0; j < isConnected.size(); j++) {
            if(isConnected[curr][j] == 1 && !visited[j]) {
                visited[j] = 1;
                q.push(j);
            }
        }
    }
}

int numOfProvincesBFS(vector<vector<int>>& isConnected) {
    int count = 0;
    vector<int> visited(isConnected.size(), 0);
    for (int i = 0; i < isConnected.size(); i++) {
        if (!visited[i]) {
            BFS(i, isConnected, visited);
            count++;
        }
    }
    return count;
}

/*
 * DFS for adjacency list
 * Time Complexity: O(V + E)
 * Space Complexity: O(V)
 */
void DFSList(int u, vector<vector<int>> &adjList , vector<int> &visited) {
    visited[u] = 1;
    for(auto i : adjList[u]) {
        if(!visited[i]) {
            DFSList(i, adjList, visited);
        }
    }
}

/*
 * BFS for adjacency list
 * Time Complexity: O(V + E)
 * Space Complexity: O(V)
 */
void BFSList(int start, vector<vector<int>> &adjList, vector<int> &visited) {
    visited[start] = 1;
    queue<int> q;
    q.push(start);
    
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        for(auto i : adjList[curr]) {
            if(!visited[i]) {
                visited[i] = 1;
                q.push(i);
            }
        }
    }
}

int numOfProvincesList(vector<vector<int>>& adjList) {
    int count = 0;
    vector<int> visited(adjList.size(), 0);
    for (int i = 0; i < adjList.size(); i++) {
        if (!visited[i]) {
            DFSList(i, adjList, visited);
            count++;
        }
    }
    return count;
}

int numOfProvincesListBFS(vector<vector<int>>& adjList) {
    int count = 0;
    vector<int> visited(adjList.size(), 0);
    for (int i = 0; i < adjList.size(); i++) {
        if (!visited[i]) {
            BFSList(i, adjList, visited);
            count++;
        }
    }
    return count;
}

int numOfProvinces(vector<vector<int>>& isConnected) {
    int count = 0;
    vector<int> visited(isConnected.size(), 0);
    for (int i = 0; i < isConnected.size(); i++) {
        if (!visited[i]) {
            DFS(i, isConnected, visited);
            count++;
        }
    }
    return count;
}

int main() {
    // ======= Test case 1: adjacency matrix =======
    vector<vector<int>> isConnected = {
        {1,1,0,0},
        {1,1,0,0},
        {0,0,1,1},
        {0,0,1,1}
    };
    cout << "Number of provinces (DFS matrix): " << numOfProvinces(isConnected) << endl;
    cout << "Number of provinces (BFS matrix): " << numOfProvincesBFS(isConnected) << endl;
    // Expected output: 2

    // ======= Test case 2: adjacency list =======
    vector<vector<int>> adjList = {
        {1},    // 0 connected to 1
        {0},    // 1 connected to 0
        {3},    // 2 connected to 3
        {2}     // 3 connected to 2
    };
    cout << "Number of provinces (DFS list): " << numOfProvincesList(adjList) << endl;
    cout << "Number of provinces (BFS list): " << numOfProvincesListBFS(adjList) << endl;
    // Expected output: 2

    // ======= Test case 3: adjacency matrix (single node provinces) =======
    vector<vector<int>> isConnected2 = {
        {1,0,0},
        {0,1,0},
        {0,0,1}
    };
    cout << "Number of provinces (DFS matrix): " << numOfProvinces(isConnected2) << endl;
    cout << "Number of provinces (BFS matrix): " << numOfProvincesBFS(isConnected2) << endl;
    // Expected output: 3

    return 0;
}
