class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        string best = "";
        int left = 0, ones = 0;

        for (int right = 0; right < n; right++) {
            if (s[right] == '1') ones++;

            // too many ones -> shrink from left
            while (ones > k) {
                if (s[left] == '1') ones--;
                left++;
            }

            // exactly k ones -> trim leading zeros, then compare
            if (ones == k) {
                int l = left;
                while (s[l] == '0') l++;
                
                int len = right - l + 1;
                if (best.empty() || len < (int)best.size() ||
                    (len == (int)best.size() && 
                     s.compare(l, len, best) < 0)) {
                    best = s.substr(l, len);
                }
            }
        }

        return best;
    }
};