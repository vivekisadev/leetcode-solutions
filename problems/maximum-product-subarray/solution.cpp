class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long long prod = 1, maxi = LONG_MIN;

        for(int i = 0; i < nums.size(); i++){
            prod *= nums[i];

            if(prod > maxi) {
                maxi = prod;
            }

            if(prod < 0){
                prod = 1;
            }
            
        }
        return maxi;
    }
};