class Solution {
public:
    int countCommas(int n) {
        int commaCount = 0;
        if (n >= 1000 && n < 1000000) {
            return commaCount += (n - 1000 + 1);
        }
        else return 0;
    }
};