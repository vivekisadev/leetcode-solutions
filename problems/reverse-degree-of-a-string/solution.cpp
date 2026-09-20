class Solution {
public:
    int reverseDegree(string s) {
        int sum = 0;
        for(int i = 1; i <= s.length(); i++) {
            sum += (i) * (26 - (s[i-1] - 'a')) ;
        }
        return sum;
    }
};