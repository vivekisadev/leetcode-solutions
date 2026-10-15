class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        for(int i = 0; i < n; i++){
            bool seen[101] = {};
            int distinct = 0;
            for(int j = i; j < n; j++){
                if(!seen[nums[j]]){
                    seen[nums[j]] = true;
                    distinct++;
                }
                res += distinct * distinct;
                
            }
        }

        return res;
    }
};