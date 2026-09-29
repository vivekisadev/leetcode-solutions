class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();

        // Path length must be even
        if ((m + n - 1) % 2) return false;
        // Quick rejects
        if (grid[0][0] == ')' || grid[m - 1][n - 1] == '(') return false;

        // Max useful balance is (m+n-1)/2 <= 100
        vector<vector<bitset<101>>> dp(m, vector<bitset<101>>(n));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                bitset<101> cur;
                if (i == 0 && j == 0) {
                    cur[0] = 1;
                } else {
                    if (i > 0) cur |= dp[i - 1][j];
                    if (j > 0) cur |= dp[i][j - 1];
                }
                dp[i][j] = (grid[i][j] == '(') ? (cur << 1) : (cur >> 1);
            }
        }
        return dp[m - 1][n - 1][0];
    }
};