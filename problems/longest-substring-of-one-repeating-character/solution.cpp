class Solution {
public:
    vector<int> longestRepeating(string s, string qc, vector<int>& qi) {
        int n = s.size();
        set<int> br = {0, n};
        for (int i = 1; i < n; i++) if (s[i] != s[i-1]) br.insert(i);

        multiset<int> lens;
        for (auto it = br.begin(); next(it) != br.end(); ++it)
            lens.insert(*next(it) - *it);

        auto ins = [&](int p) {
            auto hi = br.upper_bound(p);
            int high = *hi, low = *prev(hi);
            lens.erase(lens.find(high - low));
            lens.insert(p - low);
            lens.insert(high - p);
            br.insert(p);
        };
        auto rem = [&](int p) {
            auto it = br.find(p);
            int high = *next(it), low = *prev(it);
            lens.erase(lens.find(p - low));
            lens.erase(lens.find(high - p));
            lens.insert(high - low);
            br.erase(it);
        };

        vector<int> ans;
        for (int k = 0; k < (int)qi.size(); k++) {
            int idx = qi[k]; s[idx] = qc[k];
            for (int p : {idx, idx + 1}) {
                if (p <= 0 || p >= n) continue;
                bool should = s[p] != s[p-1];
                bool is = br.count(p);
                if (should && !is) ins(p);
                if (!should && is) rem(p);
            }
            ans.push_back(*lens.rbegin());
        }
        return ans;
    }
};