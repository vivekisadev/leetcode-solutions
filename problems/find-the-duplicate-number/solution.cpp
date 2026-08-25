class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }

        for (const auto& pair : count) {
            if (pair.second >= 2) {
                return pair.first;
            }
        }

        return 0;
    }
};