class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> sq(n);
        for(int i = 0; i < n; i++) {
            sq[i] = 1LL * nums[i] * nums[i];
        }

        sort(sq.begin(), sq.end(), greater<long long>());

        long long maxsum = 0;

        for(int i = 0; i < (n+1) / 2; i++){
            maxsum += sq[i];
        }
        for(int i = (n + 1) / 2; i < n; i++) {
            maxsum -= sq[i];
        }

        return maxsum;
    }
};