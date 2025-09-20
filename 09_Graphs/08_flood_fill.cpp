#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
    Function: floodFill
    -------------------
    Performs a BFS-based flood fill on a 2D image grid.

    Parameters:
        image - 2D vector representing the image (grid)
                0 = empty / other color
                1..N = pixel colors
        sr    - starting row
        sc    - starting column
        color - new color to fill

    Returns:
        2D vector after flood fill.

    Time Complexity:
        O(N * M) - each cell is visited at most once.

    Space Complexity:
        O(N * M) - queue may contain all pixels in the worst case.
*/

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int original = image[sr][sc];
    if(original == color) return image;

    image[sr][sc] = color;
    int row_size = image.size();
    int col_size = image[0].size();

    queue<pair<int,int>> q;
    q.push({sr, sc});

    vector<pair<int,int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};

    while(!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for(auto [dx, dy] : dirs) {
            int Dx = x + dx;
            int Dy = y + dy;
            if(Dx >= 0 && Dy >= 0 && Dx < row_size && Dy < col_size && image[Dx][Dy] == original) {
                image[Dx][Dy] = color;
                q.push({Dx, Dy});
            }
        }
    }

    return image;
}

// Driver code
int main() {
    vector<vector<int>> image = {
        {1,1,1},
        {1,1,0},
        {1,0,1}
    };

    int sr = 1, sc = 1, newColor = 2;

    vector<vector<int>> result = floodFill(image, sr, sc, newColor);

    cout << "Flood filled image:\n";
    for(auto &row : result) {
        for(auto &val : row) {
            cout << val << " ";
        }
        cout << "\n";
    }

    return 0;
}
