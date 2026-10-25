class Solution {
    int m, n;

    // turn the whole connected group of 0s (land) into 1s (water)
    void sink(vector<vector<int>>& g, int i, int j) {
        if (i < 0 || j < 0 || i >= m || j >= n || g[i][j] == 1) return;
        g[i][j] = 1;
        sink(g, i + 1, j);
        sink(g, i - 1, j);
        sink(g, i, j + 1);
        sink(g, i, j - 1);
    }

public:
    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        // 1. remove every island that touches the border
        for (int i = 0; i < m; i++) {
            sink(grid, i, 0);
            sink(grid, i, n - 1);
        }
        for (int j = 0; j < n; j++) {
            sink(grid, 0, j);
            sink(grid, m - 1, j);
        }

        // 2. every island left is closed: count and sink each one
        int count = 0;
        for (int i = 1; i < m - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                if (grid[i][j] == 0) {
                    count++;
                    sink(grid, i, j);
                }
            }
        }
        return count;
    }
};