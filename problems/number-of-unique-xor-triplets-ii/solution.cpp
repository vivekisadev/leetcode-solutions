class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        vector<int> vals(s.begin(), s.end());

        unordered_set<int> pairXor;
        for (int a : vals)
            for (int b : vals)
                pairXor.insert(a ^ b);

        unordered_set<int> tripletXor;
        for (int p : pairXor)
            for (int c : vals)
                tripletXor.insert(p ^ c);

        return tripletXor.size();
    }
};