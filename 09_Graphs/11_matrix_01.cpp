#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
 * Function: updateMatrix
 * ----------------------
 * Given a binary matrix mat, returns a matrix where each cell contains
 * the distance to the nearest 0.
 *
 * Approach:
 * - Multi-source BFS
 * - Start by pushing all 0's into the queue with distance 0.
 * - Perform BFS to update distance for all 1's.
 *
 * Time Complexity: O(m * n)
 *   - Each cell is enqueued and processed at most once.
 *
 * Space Complexity: O(m * n)
 *   - For distance matrix and BFS queue.
 */
vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int row_size = mat.size();
    int col_size = mat[0].size();

    queue<pair<int, int>> q;
    vector<vector<int>> dist(row_size, vector<int>(col_size, -1)); // -1 = not visited yet

    // Step 1: Push all 0's as starting points
    for (int i = 0; i < row_size; i++) {
        for (int j = 0; j < col_size; j++) {
            if (mat[i][j] == 0) {
                q.push({i, j});
                dist[i][j] = 0; // distance to nearest 0 is 0
            }
        }
    }

    // 4 directions
    vector<pair<int, int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};

    // Step 2: Multi-source BFS
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (auto [dx, dy] : dirs) {
            int Dx = x + dx, Dy = y + dy;
            if (Dx >= 0 && Dy >= 0 && Dx < row_size && Dy < col_size && dist[Dx][Dy] == -1) {
                dist[Dx][Dy] = dist[x][y] + 1; // update distance
                q.push({Dx, Dy});
            }
        }
    }

    return dist;
}

/*
 * Main function to test updateMatrix
 */
int main() {
    vector<vector<int>> mat = {
        {0, 0, 0},
        {0, 1, 0},
        {1, 1, 1}
    };

    vector<vector<int>> result = updateMatrix(mat);

    cout << "Resultant distance matrix:" << endl;
    for (auto& row : result) {
        for (auto& val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
