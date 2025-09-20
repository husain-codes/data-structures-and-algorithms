#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
    Function: orangesRotting
    ------------------------
    Uses multi-source BFS to calculate the minimum number of minutes 
    required to rot all fresh oranges.

    Parameters:
        grid - 2D vector representing the grid:
               0 = empty cell
               1 = fresh orange
               2 = rotten orange

    Returns:
        int -> minimum minutes needed to rot all oranges,
               or -1 if it is impossible.

    Time Complexity:
        O(N * M) 
        - Each cell is processed at most once.
        - BFS visits each orange at most once.

    Space Complexity:
        O(N * M) 
        - Queue may contain all cells in the worst case.
*/

int orangesRotting(vector<vector<int>>& grid) {
    int fresh = 0;          // Count of fresh oranges
    int minutes = -1;       // Track time (BFS levels)
    queue<pair<int,int>> q; // Multi-source BFS queue

    // Step 1: Find all initially rotten oranges and count fresh ones
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] == 2) {
                q.push({i, j});
            } else if (grid[i][j] == 1) {
                fresh++;
            }
        }
    }

    // Edge case: no fresh oranges at the start
    if (fresh == 0) return 0;

    // Possible 4 directions (up, down, left, right)
    vector<pair<int,int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};

    // Step 2: BFS (multi-source)
    while (!q.empty()) {
        int size = q.size();
        minutes++;
        for (int i = 0; i < size; i++) {
            auto [x, y] = q.front();
            q.pop();

            for (auto [dx, dy] : dirs) {
                int Dx = x + dx;
                int Dy = y + dy;
                if (Dx >= 0 && Dy >= 0 && Dx < grid.size() && Dy < grid[0].size() && grid[Dx][Dy] == 1) {
                    fresh--;            // One fresh orange becomes rotten
                    grid[Dx][Dy] = 2;   // Mark it as rotten
                    q.push({Dx, Dy});   // Add to queue for next minute
                }
            }
        }
    }

    // Step 3: If fresh oranges remain, impossible -> return -1
    return fresh == 0 ? minutes : -1;
}

// Driver Code (main function)
int main() {
    vector<vector<int>> grid = {
        {2,1,1},
        {1,1,0},
        {0,1,1}
    };

    int result = orangesRotting(grid);
    cout << "Minimum minutes to rot all oranges: " << result << endl;

    return 0;
}
