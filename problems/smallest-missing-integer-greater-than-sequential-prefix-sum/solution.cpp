class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();

        int s = nums[0];
        for(int i = 1; i < n && nums[i] == nums[i-1] + 1; i++){
            s += nums[i];
        }

        unordered_set<int> seen(nums.begin(), nums.end());
        
        while(seen.count(s)){
            s++;
        }

        return s;
    }
};