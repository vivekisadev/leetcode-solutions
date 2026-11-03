class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int max = nums[n - 1];
        int count = 0;
        for(int num : nums){
            count += (max - num);
        }
        return count;
    }
};