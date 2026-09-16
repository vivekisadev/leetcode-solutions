class Solution {
public:
    int numberOfSets(int n, int k) {
        const long long MOD = 1e9 + 7;
        vector<array<long long,2>> dp(k + 1, {0, 0});
        dp[0][0] = 1;

        for (int i = 1; i <= n; i++) {
            vector<array<long long,2>> ndp(k + 1, {0, 0});
            for (int j = 0; j <= k; j++) {
                long long prev0 = dp[j][0];
                long long prev1 = dp[j][1];
                long long prevM1_1 = (j >= 1) ? dp[j - 1][1] : 0;

                ndp[j][0] = (prev0 + prevM1_1) % MOD;
                ndp[j][1] = (prev0 + prev1 + prevM1_1) % MOD;
            }
            dp = move(ndp);
        }
        return (int)dp[k][0];
    }
};