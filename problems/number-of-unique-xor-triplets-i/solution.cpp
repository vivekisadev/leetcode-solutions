class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;                 // special small cases
        int bits = 32 - __builtin_clz(n);      // number of bits to represent n
        return 1 << bits;                      // O(1) answer
    }
};