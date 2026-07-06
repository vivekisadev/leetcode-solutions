class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        const int MOD = 1e9 + 7;
        vector<vector<long long>> dp(n, vector<long long>(n, -1));
        vector<vector<long long>> cnt(n, vector<long long>(n, 0));

        board[0][0] = '0';
        board[n-1][n-1] = '0';

        dp[n-1][n-1] = 0;
        cnt[n-1][n-1] = 1;

        int dirs[3][2] = {{1,0},{0,1},{1,1}};

        for (int i = n-1; i >= 0; i--) {
            for (int j = n-1; j >= 0; j--) {
                if (board[i][j] == 'X') continue;
                if (i == n-1 && j == n-1) continue; // start already set

                for (auto& d : dirs) {
                    int pi = i + d[0], pj = j + d[1];
                    if (pi < n && pj < n && dp[pi][pj] != -1) {
                        long long val = dp[pi][pj] + (board[i][j] - '0');
                        if (val > dp[i][j]) {
                            dp[i][j] = val;
                            cnt[i][j] = cnt[pi][pj];
                        } else if (val == dp[i][j]) {
                            cnt[i][j] = (cnt[i][j] + cnt[pi][pj]) % MOD;
                        }
                    }
                }
            }
        }

        if (dp[0][0] == -1) return {0, 0};
        return {(int)dp[0][0], (int)cnt[0][0]};
    }
};