class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0;

        for(int k = 0; k < n; k++) {
            if(nums[k] < nums[i]) i = k;
            if(nums[k] > nums[j]) j = k;
        }

        if(i > j) swap(i, j);

        int front = j + 1;
        int back = n - i;
        int mixed = (i + 1) + (n - j);

        return min({front, back, mixed});
    }
};