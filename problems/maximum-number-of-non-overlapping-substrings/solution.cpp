class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        vector<int> last(26, -1);
        for (int i = 0; i < n; i++) last[s[i] - 'a'] = i;

        vector<pair<int,int>> intervals;
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            // only start an interval at the first occurrence of this char
            bool isFirst = true;
            for (int k = 0; k < i; k++) if (s[k] - 'a' == c) { isFirst = false; break; }
            // (better: precompute 'first[]' array instead of this O(n) check — see note below)
            if (!isFirst) continue;

            int end = last[c];
            int j = i;
            while (j <= end) {
                end = max(end, last[s[j] - 'a']);
                j++;
            }
            intervals.push_back({i, end});
        }

        sort(intervals.begin(), intervals.end(),
             [](const pair<int,int>& a, const pair<int,int>& b) {
                 return a.second < b.second;
             });

        vector<string> result;
        int prevEnd = -1;
        for (auto& [start, end] : intervals) {
            if (start > prevEnd) {
                result.push_back(s.substr(start, end - start + 1));
                prevEnd = end;
            }
        }
        return result;
    }
};