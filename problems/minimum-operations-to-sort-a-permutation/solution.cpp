class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int zero = find(nums.begin(), nums.end(), 0) - nums.begin();

        // walk cyclically from the position of 0 in direction `step` (+1 or -1);
        // the values must be non-decreasing along the way
        auto check = [&](int step) {
            for (int i = 1; i < n; i++) {
                int prev = ((zero + (i - 1) * step) % n + n) % n;
                int curr = ((zero + i * step) % n + n) % n;
                if (nums[prev] > nums[curr]) return false;
            }
            return true;
        };

        int ans = INT_MAX;
        if (check(1)) {                         // array is a rotation of sorted
            ans = min(ans, zero);               // rotate left `zero` times
            ans = min(ans, n - zero + 2);       // reverse, rotate n-zero, reverse
        }
        if (check(-1)) {                        // array is a reversed rotation of sorted
            ans = min(ans, zero + 2);           // rotate zero+1 times, then reverse
            ans = min(ans, n - zero);           // reverse, then rotate n-zero-1 times
        }
        return ans == INT_MAX ? -1 : ans;
    }
};