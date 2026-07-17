class Solution {
public:
    int subsequencePairCount(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        int V = 200;
        vector<vector<long long>> dp(V + 1, vector<long long>(V + 1, 0));
        dp[0][0] = 1;

        for (int x : nums) {
            vector<vector<long long>> ndp = dp; // option: leave x unused
            for (int a = 0; a <= V; a++) {
                for (int b = 0; b <= V; b++) {
                    if (dp[a][b] == 0) continue;
                    long long val = dp[a][b];

                    int na = (a == 0) ? x : __gcd(a, x);
                    ndp[na][b] = (ndp[na][b] + val) % MOD;

                    int nb = (b == 0) ? x : __gcd(b, x);
                    ndp[a][nb] = (ndp[a][nb] + val) % MOD;
                }
            }
            dp = ndp;
        }

        long long ans = 0;
        for (int g = 1; g <= V; g++)
            ans = (ans + dp[g][g]) % MOD;

        return (int)ans;
    }
};