class Solution {
public:
    long long sumAndMultiply(int n) {
        string digits = to_string(n);
        string nonZero = "";
        long long sum = 0;
        
        for (char c : digits) {
            int d = c - '0';
            sum += d;
            if (d != 0) {
                nonZero += c;
            }
        }
        
        long long x = nonZero.empty() ? 0 : stoll(nonZero);
        return x * sum;
    }
};