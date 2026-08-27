class Solution {
public:
    int trailingZeroes(int n) {
        long long fac  = 1;
        for(int i = n; i > 0; i--){
            fac *= i;
        }
        int trailZeros = 0;
        while(fac > 0) {
            if(fac % 10 == 0) {
                trailZeros++;
                fac /= 10;
            }
            else break;
            
        }

        return trailZeros;
    }
};