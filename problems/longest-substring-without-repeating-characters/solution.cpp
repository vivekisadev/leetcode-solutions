class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seen;
        int maxL  =0, l =0;

        for( int r =0; r <s.length(); r++){
            while(seen.count(s[r])){
                seen.erase(s[l]);
                l++;
            }
            seen.insert(s[r]);
            maxL = max(maxL,r-l+1);
        }
        return maxL;
    }
};