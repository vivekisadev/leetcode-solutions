class Solution {
public:
    int stoneGameVIII(std::vector<int>& stones) {
        int n = stones.size();
        
        // Step 1: Compute prefix sums in-place to save memory
        for (int i = 1; i < n; ++i) {
            stones[i] += stones[i - 1];
        }
        
        // Step 2: Initialize DP with the last possible move.
        // If a player takes the whole array, the game ends.
        int dp = stones.back();
        
        // Step 3: Work backwards from the second-to-last index down to 1
        // (Alice must take at least 2 stones, meaning prefix index >= 1)
        for (int i = n - 2; i > 0; --i) {
            dp = std::max(dp, stones[i] - dp);
        }
        
        return dp;
    }
};