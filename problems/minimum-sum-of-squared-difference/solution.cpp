class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long k = (long long)k1 + k2;

        int mx = 0;
        for (int i = 0; i < n; i++)
            mx = max(mx, abs(nums1[i] - nums2[i]));

        vector<long long> cnt(mx + 1, 0);
        for (int i = 0; i < n; i++)
            cnt[abs(nums1[i] - nums2[i])]++;

        // Shave the largest differences down first
        for (int v = mx; v >= 1 && k > 0; v--) {
            if (cnt[v] == 0) continue;
            long long take = min(k, cnt[v]);
            cnt[v] -= take;
            cnt[v - 1] += take;
            k -= take;
        }

        long long res = 0;
        for (long long v = 1; v <= mx; v++)
            res += cnt[v] * v * v;
        return res;
    }
};