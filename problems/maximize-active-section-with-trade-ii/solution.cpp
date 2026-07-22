class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.size();
        int ones = count(s.begin(), s.end(), '1');

        vector<int> gStart, gEnd;
        vector<int> gid(n, -1);
        for (int i = 0; i < n; ) {
            if (s[i] == '0') {
                int j = i;
                while (j < n && s[j] == '0') j++;
                int idx = gStart.size();
                gStart.push_back(i);
                gEnd.push_back(j - 1);
                for (int k = i; k < j; k++) gid[k] = idx;
                i = j;
            } else i++;
        }
        int G = gStart.size();
        vector<int> len(G);
        for (int i = 0; i < G; i++) len[i] = gEnd[i] - gStart[i] + 1;

        int P = max(0, G - 1);
        vector<int> pairSum(P);
        for (int k = 0; k < P; k++) pairSum[k] = len[k] + len[k + 1];

        int LOG = 1;
        while ((1 << LOG) <= max(1, P)) LOG++;
        vector<vector<int>> st(LOG, vector<int>(max(P,1), 0));
        if (P > 0) {
            st[0] = pairSum;
            for (int k = 1; k < LOG; k++)
                for (int i = 0; i + (1 << k) <= P; i++)
                    st[k][i] = max(st[k-1][i], st[k-1][i + (1 << (k-1))]);
        }
        vector<int> logTable(P + 1, 0);
        for (int i = 2; i <= P; i++) logTable[i] = logTable[i/2] + 1;
        auto rangeMax = [&](int l, int r) -> int {
            if (l > r) return INT_MIN;
            int k = logTable[r - l + 1];
            return max(st[k][l], st[k][r - (1 << k) + 1]);
        };

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto& q : queries) {
            int l = q[0], r = q[1];
            int best = ones; // no trade

            bool lZero = s[l] == '0';
            bool rZero = s[r] == '0';
            int glid = lZero ? gid[l] : -1;
            int grid = rZero ? gid[r] : -1;

            if (lZero && rZero && glid == grid) {
                ans.push_back(best);
                continue;
            }

            int leftPartial  = lZero ? (gEnd[glid] - l + 1) : -1;
            int rightPartial = rZero ? (r - gStart[grid] + 1) : -1;

            int fStart = lZero
                ? glid + 1
                : int(upper_bound(gStart.begin(), gStart.end(), l) - gStart.begin());
            int fEnd = rZero
                ? grid - 1
                : int(lower_bound(gStart.begin(), gStart.end(), r) - gStart.begin()) - 1;

            if (fStart <= fEnd - 1)
                best = max(best, ones + rangeMax(fStart, fEnd - 1));
            if (lZero && fStart <= fEnd)
                best = max(best, ones + leftPartial + len[fStart]);
            if (rZero && fStart <= fEnd)
                best = max(best, ones + len[fEnd] + rightPartial);
            if (lZero && rZero && fStart > fEnd)
                best = max(best, ones + leftPartial + rightPartial);

            ans.push_back(best);
        }

        return ans;
    }
};
