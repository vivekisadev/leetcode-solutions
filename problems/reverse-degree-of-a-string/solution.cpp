class Solution {
public:
    int reverseDegree(string s) {
        int sum = 0;
        for(int i = 1; i <= s.length(); i++) {
            sum += ((123 - int(s[i-1])) * i);
        }
        return sum;
    }
};