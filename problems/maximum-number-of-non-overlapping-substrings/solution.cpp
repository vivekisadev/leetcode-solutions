class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        vector<int> first(26, -1), last(26, -1);
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            if (first[c] == -1) first[c] = i;
            last[c] = i;
        }

        vector<pair<int,int>> intervals;
        for (int c = 0; c < 26; c++) {
            if (first[c] == -1) continue;
            int start = first[c];
            int expandIt = last[c];   // grows as farther-reaching chars are found
            bool acceptIt = true;     // flips false if something leaks before start
            int slideIt = start;      // scans the (possibly growing) window
            while (slideIt <= expandIt) {
                int c2 = s[slideIt] - 'a';
                if (first[c2] < start) { acceptIt = false; break; }
                expandIt = max(expandIt, last[c2]);
                slideIt++;
            }
            if (acceptIt) intervals.push_back({start, expandIt});
        }

        sort(intervals.begin(), intervals.end(),
             [](auto& a, auto& b) { return a.second < b.second; });

        vector<string> result;
        int prevEnd = -1;
        for (auto& [st, en] : intervals) {
            if (st > prevEnd) {
                result.push_back(s.substr(st, en - st + 1));
                prevEnd = en;
            }
        }
        return result;
    }
};