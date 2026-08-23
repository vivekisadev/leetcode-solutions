class Solution {
public:
    bool sumGame(string num) {
        int n = num.length();
        int sumLeft = 0, sumRight = 0;
        int cntLeft = 0, cntRight = 0;

        for (int i = 0; i < n / 2; i++) {
            if (num[i] == '?') cntLeft++;
            else sumLeft += num[i] - '0';
        }
        for (int i = n / 2; i < n; i++) {
            if (num[i] == '?') cntRight++;
            else sumRight += num[i] - '0';
        }

        int diff = sumLeft - sumRight;
        int totalQ = cntLeft + cntRight;

        if (totalQ % 2 == 1) return true;             
        return diff != 9 * (cntRight - cntLeft) / 2; 
    }
};