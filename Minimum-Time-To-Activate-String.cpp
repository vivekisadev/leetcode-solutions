class Solution {
public:
    long long calc(long long L) { return L * (L + 1) / 2; }

    int minTime(string s, vector<int>& order, int k) {
        int n = s.size();
        set<int> stars;
        stars.insert(-1);
        stars.insert(n);

        long long total = calc(n);
        long long invalid = calc(n); // one big gap of length n initially

        for (int t = 0; t < n; t++) {
            int p = order[t];

            auto it = stars.lower_bound(p); // right neighbor star (p not yet inserted)
            int right = *it;
            int left = *prev(it);

            long long L = right - left - 1;   // old gap length
            invalid -= calc(L);

            long long L1 = p - left - 1;      // new left gap
            long long L2 = right - p - 1;     // new right gap
            invalid += calc(L1) + calc(L2);

            stars.insert(p);

            long long valid = total - invalid;
            if (valid >= (long long)k) return t;
        }

        return -1;
    }
};