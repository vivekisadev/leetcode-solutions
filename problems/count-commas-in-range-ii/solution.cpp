class Solution {
public:
    long long countCommas(long long n) {
        int ans = 0;
        int x = 1000;
        while(x <= n){
            ans += n - x + 1;
            x *= 1000;
        }
        return ans;
    }
};