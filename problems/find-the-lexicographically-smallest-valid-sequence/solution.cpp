class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size(), m = word2.size();

    
        vector<int> suf(n + 1, m);
        int j = m;
        for (int i = n - 1; i >= 0; i--) {
            if (j > 0 && word1[i] == word2[j - 1]) j--;
            suf[i] = j;
        }

        vector<int> res;
        int i = 0, k = 0;
        bool usedMismatch = false;

        while (i < n && k < m) {
            if (word1[i] == word2[k]) {
                
                res.push_back(i);
                i++; k++;
            } else if (!usedMismatch && suf[i + 1] <= k + 1) {
                res.push_back(i);
                usedMismatch = true;
                i++; k++;
            } else {
                i++;
            }
        }

        if (k < m) return {}; 
        return res;
    }
};