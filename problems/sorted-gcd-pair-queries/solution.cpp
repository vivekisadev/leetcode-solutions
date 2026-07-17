class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int maxVal = *max_element(nums.begin(), nums.end());
        vector<int> cnt(maxVal + 1, 0);
        for (int x : nums) cnt[x]++;

        // multiple[d] = count of numbers divisible by d
        vector<long long> multiple(maxVal + 1, 0);
        for (int d = 1; d <= maxVal; d++)
            for (int k = d; k <= maxVal; k += d)
                multiple[d] += cnt[k];

        // exact[d] = pairs with gcd exactly d
        vector<long long> exact(maxVal + 1, 0);
        for (int d = maxVal; d >= 1; d--) {
            long long total = multiple[d] * (multiple[d] - 1) / 2;
            for (int k = 2 * d; k <= maxVal; k += d)
                total -= exact[k];
            exact[d] = total;
        }

        // prefix[d] = pairs with gcd <= d
        vector<long long> prefix(maxVal + 1, 0);
        for (int d = 1; d <= maxVal; d++)
            prefix[d] = prefix[d - 1] + exact[d];

        vector<int> ans;
        for (long long q : queries) {
            int lo = 1, hi = maxVal;
            while (lo < hi) {
                int mid = (lo + hi) / 2;
                if (prefix[mid] > q) hi = mid;
                else lo = mid + 1;
            }
            ans.push_back(lo);
        }
        return ans;
    }
};