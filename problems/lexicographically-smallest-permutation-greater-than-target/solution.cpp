class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        vector<int> cnt(26, 0);
        for (char ch : s) cnt[ch - 'a']++;

        // prefixStack[i] = letter counts remaining BEFORE placing position i
        vector<vector<int>> prefixStack;
        prefixStack.push_back(cnt);

        vector<int> counts = cnt;
        int matchLen = 0;
        while (matchLen < n) {
            int idx = target[matchLen] - 'a';
            if (counts[idx] > 0) {
                counts[idx]--;
                matchLen++;
                prefixStack.push_back(counts);
            } else {
                break;
            }
        }

        int start = min(matchLen, n - 1);
        for (int i = start; i >= 0; i--) {
            vector<int> avail = prefixStack[i];
            int tIdx = target[i] - 'a';

            int chosen = -1;
            for (int c = tIdx + 1; c < 26; c++) {
                if (avail[c] > 0) {
                    chosen = c;
                    break;
                }
            }

            if (chosen != -1) {
                avail[chosen]--;
                string res = target.substr(0, i);
                res += (char)('a' + chosen);
                for (int c = 0; c < 26; c++) {
                    res += string(avail[c], (char)('a' + c));
                }
                return res;
            }
        }

        return "";
    }
};