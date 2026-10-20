class Solution {
public:
    long long sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        long long res = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k) continue;

            bool ok = true;
            int prevMax = INT_MIN;

            for (int s = 0; s < n && ok; s += k) {
                int descents = 0, mn = INT_MAX, mx = INT_MIN;
                for (int j = 0; j < k; j++) {
                    int cur = nums[s + j];
                    int nxt = nums[s + (j + 1) % k];   // cyclic neighbour
                    if (cur > nxt) descents++;
                    mn = min(mn, cur);
                    mx = max(mx, cur);
                }
                // block must be a rotation of a sorted block,
                // and must not go below the previous block's max
                if (descents > 1 || mn < prevMax) ok = false;
                prevMax = mx;
            }
            if (ok) res += k;
        }
        return res;
    }
};