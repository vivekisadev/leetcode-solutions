class Solution {
    const long long MOD = 1e9 + 7;
    vector<vector<long long>> C;

    long long dfs(vector<int>& a) {
        int n = a.size();
        if (n <= 2) return 1;  // 0, 1 or 2 elements: only one valid order

        vector<int> left, right;
        for (int i = 1; i < n; i++)
            (a[i] < a[0] ? left : right).push_back(a[i]);

        // interleave left and right orders: choose which of the n-1 slots go to left
        return C[n - 1][left.size()] * dfs(left) % MOD * dfs(right) % MOD;
    }

public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();

        // Pascal's triangle mod p
        C.assign(n, vector<long long>(n, 0));
        for (int i = 0; i < n; i++) {
            C[i][0] = 1;
            for (int j = 1; j <= i; j++)
                C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
        }

        return (dfs(nums) - 1 + MOD) % MOD;  // subtract the original ordering
    }
};