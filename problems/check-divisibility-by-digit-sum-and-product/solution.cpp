class Solution {
public:
    bool checkDivisibility(int n) {
        string s = to_string(n);
        int sum = 0;
        long long prd = 1;
        for( char ch : s){
            int digit = ch - '0';
            sum += digit;
            prd *= digit;
        }
        long long f = sum + prd;

        if( n % f == 0) return true;
        else return false;
    }
};