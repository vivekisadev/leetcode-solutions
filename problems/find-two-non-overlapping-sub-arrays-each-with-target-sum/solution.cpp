class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> best(n, INT_MAX);   // best[i] = shortest valid subarray ending at or before i
        int ans = INT_MAX;
        int left = 0;
        long long sum = 0;

        for (int right = 0; right < n; right++) {
            sum += arr[right];
            while (sum > target) {
                sum -= arr[left];
                left++;
            }
            if (sum == target) {
                int len = right - left + 1;
                if (left > 0 && best[left - 1] != INT_MAX) {
                    ans = min(ans, best[left - 1] + len);
                }
                best[right] = (right > 0) ? min(best[right - 1], len) : len;
            } else {
                best[right] = (right > 0) ? best[right - 1] : INT_MAX;
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};