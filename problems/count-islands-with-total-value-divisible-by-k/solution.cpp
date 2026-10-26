class Solution {
    int m, n;

    // sinks the island starting at (i, j) and returns the sum of its cells
    long long dfs(vector<vector<int>>& g, int i, int j) {
        if (i < 0 || j < 0 || i >= m || j >= n || g[i][j] == 0) return 0;
        long long sum = g[i][j];
        g[i][j] = 0;  // mark visited
        sum += dfs(g, i + 1, j);
        sum += dfs(g, i - 1, j);
        sum += dfs(g, i, j + 1);
        sum += dfs(g, i, j - 1);
        return sum;
    }

public:
    int countIslands(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();
        int count = 0;

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] > 0 && dfs(grid, i, j) % k == 0)
                    count++;

        return count;
    }
};