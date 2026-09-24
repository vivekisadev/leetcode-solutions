class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total = 0;
        for (int num : nums) total += num;
        
        int target = total - x;
        if (target < 0) return -1;
        if (target == 0) return nums.size();
        
        int left = 0;
        int currSum = 0;
        int maxLen = -1;
        
        for (int right = 0; right < nums.size(); right++) {
            currSum += nums[right];
            while (currSum > target && left <= right) {
                currSum -= nums[left];
                left++;
            }
            if (currSum == target) {
                maxLen = max(maxLen, right - left + 1);
            }
        }
        
        return maxLen == -1 ? -1 : (int)nums.size() - maxLen;
    }
};