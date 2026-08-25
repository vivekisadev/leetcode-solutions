class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int sm = k;
        while(sm <= 100){
            if(find(nums.begin(), nums.end(), sm) != nums.end()){
                sm += k;
            }
            else break;
        }
        return sm;
    }
};