class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.length();
        array<int, 26> count{};
        int left = 0, maxLen = 0;

        for( int right = 0; right < n; right++){
            count[s[right] - 'a']++;

            while(count[s[right] - 'a'] > 2){
                count[s[left] - 'a']--;
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
        

    }
};