class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> last_idx(256, 0); 
        vector<bool> seen(256, false); 
        string result = "";            

        for (int i = 0; i < s.length(); i++) {
            last_idx[s[i]] = i;
        }

        for (int i = 0; i < s.length(); i++) {
            char c = s[i];

            if (seen[c]) continue;

            while (!result.empty() && result.back() > c && last_idx[result.back()] > i) {
                seen[result.back()] = false;
                result.pop_back();
            }

            result.push_back(c);
            seen[c] = true;
        }

        return result;
    }
};
