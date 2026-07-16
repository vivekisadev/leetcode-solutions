#include <numeric>
using namespace std;

class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix_gcd;
        int mx = 0;
        for(int num : nums){
            mx = max(mx, num);
            prefix_gcd.push_back(gcd(num, mx));

        }
        sort(prefix_gcd.begin(),prefix_gcd.end());

        int lo = 0, hi = n-1;
        long long total = 0;
        while(lo < hi){
            total += gcd(prefix_gcd[lo],prefix_gcd[hi]);
            lo++;
            hi--;
        }

        return total;

    }
};