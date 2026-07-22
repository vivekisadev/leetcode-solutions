class Solution {
public:
    int findGCD(vector<int>& nums) {
        nums.sort(begin(), end());
        int n = nums.size();
        int res = gcd(nums[0], nums[n-1]);
        return res;
    }
};