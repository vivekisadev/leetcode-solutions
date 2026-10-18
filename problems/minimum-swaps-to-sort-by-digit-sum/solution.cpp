class Solution {
    int digitSum(int x) {
        int s = 0;
        while (x) { s += x % 10; x /= 10; }
        return s;
    }

public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        // (digit sum, value, original index)
        vector<array<int, 3>> v(n);
        for (int i = 0; i < n; i++)
            v[i] = {digitSum(nums[i]), nums[i], i};

        sort(v.begin(), v.end());  // by digit sum, then by value

        // target position i must hold the element currently at v[i][2]
        vector<bool> vis(n, false);
        int swaps = 0;
        for (int i = 0; i < n; i++) {
            if (vis[i] || v[i][2] == i) continue;
            int len = 0, j = i;
            while (!vis[j]) {
                vis[j] = true;
                j = v[j][2];
                len++;
            }
            swaps += len - 1;
        }
        return swaps;
    }
};