class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        string t = "1" + s + "1";
        int n = t.size();
        
        // build run-length list of t: pairs (char, length)
        vector<pair<char,int>> runs;
        int i = 0;
        while (i < n) {
            int j = i;
            while (j < n && t[j] == t[i]) j++;
            runs.push_back({t[i], j - i});
            i = j;
        }
        
        int ones = count(s.begin(), s.end(), '1');
        int bestGain = 0;
        
        // runs[0] and runs.back() are the augmented '1' runs — skip as "sacrificed" block
        for (int k = 1; k + 1 < (int)runs.size(); k++) {
            if (runs[k].first == '1') {
                int gain = runs[k - 1].second + runs[k + 1].second;
                bestGain = max(bestGain, gain);
            }
        }
        
        return ones + bestGain;
    }
};