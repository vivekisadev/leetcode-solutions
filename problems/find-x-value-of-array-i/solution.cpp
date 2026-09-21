class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);
        vector<long long> dp(k, 0);   // dp[r]: subarrays ending here with product % k == r

        for (int num : nums) {
            vector<long long> newDp(k, 0);
            int numMod = num % k;

            // subarray consisting of just this element
            newDp[numMod] = 1;

            // extend every previous subarray by this element
            for (int r = 0; r < k; ++r) {
                int newMod = (int)((long long)r * numMod % k);
                newDp[newMod] += dp[r];
            }

            for (int r = 0; r < k; ++r)
                ans[r] += newDp[r];

            dp = newDp;
        }

        return ans;
    }
};