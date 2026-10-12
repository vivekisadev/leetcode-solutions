class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const long long MOD = 1e9 + 7;
        int cnt[30] = {};

        // Count how many numbers have each bit set
        for (int x : nums)
            for (int b = 0; b < 30; b++)
                if (x >> b & 1) cnt[b]++;

        long long res = 0;
        for (int i = 0; i < k; i++) {
            long long cur = 0;
            // Build the largest number possible from the remaining bits
            for (int b = 0; b < 30; b++) {
                if (cnt[b] > 0) {
                    cnt[b]--;
                    cur |= 1LL << b;
                }
            }
            cur %= MOD;
            res = (res + cur * cur) % MOD;
        }
        return (int)res;
    }
};