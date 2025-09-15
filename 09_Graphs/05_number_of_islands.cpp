#include<iostream>
#include<vector>

using namespace std;

/*
DFS function to mark all connected land ('1') as visited.
- grid: 2D grid representing map of '1' (land) and '0' (water)
- i, j: current cell coordinates
Time Complexity: O(m*n) in worst case (each cell visited once)
Space Complexity: O(m*n) recursion stack in worst case (all land connected)
*/
void dfs(vector<vector<char>> &grid, int i, int j) {
    // Base condition: out of bounds or water cell
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == '0') 
        return;

    grid[i][j] = '0'; // mark current cell as visited

    // Explore all 4 directions
    dfs(grid, i+1, j); // down
    dfs(grid, i-1, j); // up
    dfs(grid, i, j-1); // left
    dfs(grid, i, j+1); // right
}

/*
Function to count the number of islands in a grid.
- Iterate through each cell
- When unvisited land ('1') is found, call dfs to mark entire island visited
- Increment island count for each DFS initiation
Time Complexity: O(m*n) – each cell visited once
Space Complexity: O(m*n) recursion stack worst case
*/
int numberOfIslands(vector<vector<char>> &grid) {
    if(grid.empty()) return 0; // empty grid check

    int count = 0;
    for (int i = 0; i < grid.size(); i++) {        // loop over rows
        for (int j = 0; j < grid[0].size(); j++) { // loop over columns
            if (grid[i][j] == '1') {               // unvisited land found
                dfs(grid, i, j);                   // mark entire island
                count++;                            // increment island count
            }
        }
    } 
    return count;
}

int main() {
    // Example grid
    vector<vector<char>> grid = {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','1'}
    };
    
    cout << numberOfIslands(grid); // Output number of islands
}
