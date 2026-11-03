class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxi = 0;
        for(int num : nums){
            maxi = max(maxi, num);
        }
        int ans = 0;
        for(int num : nums){
            ans += (maxi - num);
        }
        return ans;
    }
};